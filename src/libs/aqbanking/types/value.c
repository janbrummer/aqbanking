/***************************************************************************
 $RCSfile$
                             -------------------
    cvs         : $Id$
    begin       : Mon Apr 05 2004
    copyright   : (C) 2004 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include "value_p.h"
#include <gwenhywfar/debug.h>
#include <gwenhywfar/misc.h>
#include <gwenhywfar/buffer.h>
#include <gwenhywfar/text.h>

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif



AB_VALUE *AB_Value_new(double value, const char *currency){
  AB_VALUE *v;

  GWEN_NEW_OBJECT(AB_VALUE, v);
  v->value=value;
  if (currency)
    v->currency=strdup(currency);
  v->isValid=1;
  return v;
}



AB_VALUE *AB_Value_dup(const AB_VALUE *v){
  AB_VALUE *vc;

  assert(v);
  GWEN_NEW_OBJECT(AB_VALUE, vc);
  vc->value=v->value;
  if (v->currency)
    vc->currency=strdup(v->currency);
  vc->isValid=v->isValid;
  return vc;
}



AB_VALUE *AB_Value_FromDb(GWEN_DB_NODE *db){
  AB_VALUE *vc;
  const char *p;
  GWEN_BUFFER *buf;

  p=GWEN_DB_GetCharValue(db, "value", 0, 0);
  if (!p)
    return 0;
  buf=GWEN_Buffer_new(0, 128, 0, 1);
  GWEN_Buffer_AppendString(buf, p);
  GWEN_Buffer_AppendByte(buf, ':');
  p=GWEN_DB_GetCharValue(db, "currency", 0, "EUR");
  GWEN_Buffer_AppendString(buf, p);
  vc=AB_Value_FromString(GWEN_Buffer_GetStart(buf));
  GWEN_Buffer_free(buf);
  return vc;
}



int AB_Value_ToDb(const AB_VALUE *v, GWEN_DB_NODE *db) {
  GWEN_BUFFER *buf;

  buf=GWEN_Buffer_new(0, 128, 0, 1);
  if (GWEN_Text_DoubleToBuffer(v->value, buf)) {
    GWEN_Buffer_free(buf);
    return -1;
  }
  GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS,
                       "value", GWEN_Buffer_GetStart(buf));
  GWEN_Buffer_free(buf);
  if (v->currency)
    GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS,
                         "currency", v->currency);
  return 0;
}



AB_VALUE *AB_Value_FromString(const char *s){
  AB_VALUE *v;

  assert(s);
  while(*s && isspace(*s)) s++;
  if (!*s) {
    DBG_INFO(0, "Empty value");
    v=AB_Value_new(0.0, 0);
    v->isValid=0;
    return v;
  }
  else {
    unsigned int i;
    double d;
    const char *currency;
    char c;
    int rv;
    char numbuf[128];
#ifdef HAVE_SETLOCALE
    const char *currentLocale;
#endif

    /* get floating point */
    i=0;
    c=0;
    while(*s) {
      c=*s;
      if (c==',')
        c='.';
      else if (c==':')
        break;
      else if (!isdigit(c)) {
        DBG_ERROR(0, "Non-digit character in value");
        return 0;
      }
      assert(i<sizeof(numbuf)-1);
      numbuf[i++]=c;
      s++;
    }
    if (c=='.') {
      /* last was comma, make sure at least one digit follows */
      assert(i<sizeof(numbuf)-1);
      numbuf[i++]='0';
    }
    numbuf[i]=0;
#ifdef HAVE_SETLOCALE
    currentLocale=setlocale(LC_NUMERIC, 0);
    setlocale(LC_NUMERIC, "C");
#endif
    rv=sscanf(numbuf, "%lf", &d);
#ifdef HAVE_SETLOCALE
    setlocale(LC_NUMERIC, currentLocale);
#endif
    if (rv!=1) {
      DBG_ERROR(0, "Could not read floating point value");
      return 0;
    }

    if (*s) {
      if (*s!=':') {
        DBG_ERROR(0, "\":\" or end of string expected");
        return 0;
      }
      s++;
      currency=s;
    }
    else
      currency=0;
    v=AB_Value_new(d, currency);
    return v;
  }
}



void AB_Value_free(AB_VALUE *v){
  if (v) {
    free(v->currency);

    GWEN_FREE_OBJECT(v);
  }
}



double AB_Value_GetValue(const AB_VALUE *v){
  assert(v);
  return v->value;
}



void AB_Value_SetValue(AB_VALUE *v, double d){
  assert(v);
  v->value=d;
}



const char *AB_Value_GetCurrency(const AB_VALUE *v){
  assert(v);
  return v->currency;
}



void AB_Value_SetCurrency(AB_VALUE *v, const char *s){
  assert(v);
  free(v->currency);
  if (s) v->currency=strdup(s);
  else v->currency=0;
}



int AB_Value_IsValid(const AB_VALUE *v){
  assert(v);
  return v->isValid;
}








