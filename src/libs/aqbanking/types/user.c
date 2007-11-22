/* This file is auto-generated from "user.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "user_p.h"
#include <gwenhywfar/misc.h>
#include <gwenhywfar/db.h>
#include <gwenhywfar/debug.h>
#include <assert.h>
#include <stdlib.h>
#include <strings.h>

#include "userfns_l.h"


GWEN_INHERIT_FUNCTIONS(AB_USER)
GWEN_LIST_FUNCTIONS(AB_USER, AB_User)
GWEN_LIST2_FUNCTIONS(AB_USER, AB_User)




AB_USER *AB_User__new() {
  AB_USER *st;

  GWEN_NEW_OBJECT(AB_USER, st)
  st->_usage=1;
  GWEN_INHERIT_INIT(AB_USER, st)
  GWEN_LIST_INIT(AB_USER, st)
  st->data=GWEN_DB_Group_new("data");
  return st;
}


void AB_User_free(AB_USER *st) {
  if (st) {
    assert(st->_usage);
    if (--(st->_usage)==0) {
  GWEN_INHERIT_FINI(AB_USER, st)
  if (st->backendName)
    free(st->backendName);
  if (st->userName)
    free(st->userName);
  if (st->userId)
    free(st->userId);
  if (st->customerId)
    free(st->customerId);
  if (st->country)
    free(st->country);
  if (st->bankCode)
    free(st->bankCode);
  if (st->data)
    GWEN_DB_Group_free(st->data);
  GWEN_LIST_FINI(AB_USER, st)
  GWEN_FREE_OBJECT(st);
    }
  }

}




int AB_User_toDb(const AB_USER *st, GWEN_DB_NODE *db) {
  assert(st);
  assert(db);
  if (GWEN_DB_SetIntValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "uniqueId", st->uniqueId))
    return -1;
  if (st->backendName)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "backendName", st->backendName))
      return -1;
  if (st->userName)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "userName", st->userName))
      return -1;
  if (st->userId)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "userId", st->userId))
      return -1;
  if (st->customerId)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "customerId", st->customerId))
      return -1;
  if (st->country)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "country", st->country))
      return -1;
  if (st->bankCode)
    if (GWEN_DB_SetCharValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "bankCode", st->bankCode))
      return -1;
  if (GWEN_DB_SetIntValue(db, GWEN_DB_FLAGS_OVERWRITE_VARS, "lastSessionId", st->lastSessionId))
    return -1;
  if (st->data)
    if (AB_User__dbToDb(st->data, GWEN_DB_GetGroup(db, GWEN_DB_FLAGS_DEFAULT, "data")))
      return -1;
  return 0;
}


int AB_User_ReadDb(AB_USER *st, GWEN_DB_NODE *db) {
  assert(st);
  assert(db);
  AB_User_SetUniqueId(st, GWEN_DB_GetIntValue(db, "uniqueId", 0, 0));
  AB_User_SetBackendName(st, GWEN_DB_GetCharValue(db, "backendName", 0, 0));
  AB_User_SetUserName(st, GWEN_DB_GetCharValue(db, "userName", 0, 0));
  AB_User_SetUserId(st, GWEN_DB_GetCharValue(db, "userId", 0, 0));
  AB_User_SetCustomerId(st, GWEN_DB_GetCharValue(db, "customerId", 0, 0));
  AB_User_SetCountry(st, GWEN_DB_GetCharValue(db, "country", 0, "de"));
  AB_User_SetBankCode(st, GWEN_DB_GetCharValue(db, "bankCode", 0, 0));
  AB_User_SetLastSessionId(st, GWEN_DB_GetIntValue(db, "lastSessionId", 0, 0));
  if (1) { /* for local vars */
    GWEN_DB_NODE *dbT;

    dbT=GWEN_DB_GetGroup(db, GWEN_PATH_FLAGS_NAMEMUSTEXIST, "data");
    if (dbT) {
  if (st->data)
    GWEN_DB_Group_free(st->data);
  st->data=GWEN_DB_Group_dup(dbT);
}
  }
  return 0;
}






uint32_t AB_User_GetUniqueId(const AB_USER *st) {
  assert(st);
  return st->uniqueId;
}


void AB_User_SetUniqueId(AB_USER *st, uint32_t d) {
  assert(st);
  st->uniqueId=d;
  st->_modified=1;
}




const char *AB_User_GetBackendName(const AB_USER *st) {
  assert(st);
  return st->backendName;
}


void AB_User_SetBackendName(AB_USER *st, const char *d) {
  assert(st);
  if (st->backendName)
    free(st->backendName);
  if (d && *d)
    st->backendName=strdup(d);
  else
    st->backendName=0;
  st->_modified=1;
}




const char *AB_User_GetUserName(const AB_USER *st) {
  assert(st);
  return st->userName;
}


void AB_User_SetUserName(AB_USER *st, const char *d) {
  assert(st);
  if (st->userName)
    free(st->userName);
  if (d && *d)
    st->userName=strdup(d);
  else
    st->userName=0;
  st->_modified=1;
}




const char *AB_User_GetUserId(const AB_USER *st) {
  assert(st);
  return st->userId;
}


void AB_User_SetUserId(AB_USER *st, const char *d) {
  assert(st);
  if (st->userId)
    free(st->userId);
  if (d && *d)
    st->userId=strdup(d);
  else
    st->userId=0;
  st->_modified=1;
}




const char *AB_User_GetCustomerId(const AB_USER *st) {
  assert(st);
  return st->customerId;
}


void AB_User_SetCustomerId(AB_USER *st, const char *d) {
  assert(st);
  if (st->customerId)
    free(st->customerId);
  if (d && *d)
    st->customerId=strdup(d);
  else
    st->customerId=0;
  st->_modified=1;
}




const char *AB_User_GetCountry(const AB_USER *st) {
  assert(st);
  return st->country;
}


void AB_User_SetCountry(AB_USER *st, const char *d) {
  assert(st);
  if (st->country)
    free(st->country);
  if (d && *d)
    st->country=strdup(d);
  else
    st->country=0;
  st->_modified=1;
}




const char *AB_User_GetBankCode(const AB_USER *st) {
  assert(st);
  return st->bankCode;
}


void AB_User_SetBankCode(AB_USER *st, const char *d) {
  assert(st);
  if (st->bankCode)
    free(st->bankCode);
  if (d && *d)
    st->bankCode=strdup(d);
  else
    st->bankCode=0;
  st->_modified=1;
}




uint32_t AB_User_GetLastSessionId(const AB_USER *st) {
  assert(st);
  return st->lastSessionId;
}


void AB_User_SetLastSessionId(AB_USER *st, uint32_t d) {
  assert(st);
  st->lastSessionId=d;
  st->_modified=1;
}




GWEN_DB_NODE *AB_User_GetData(const AB_USER *st) {
  assert(st);
  return st->data;
}


void AB_User_SetData(AB_USER *st, GWEN_DB_NODE *d) {
  assert(st);
  if (st->data)
    GWEN_DB_Group_free(st->data);
  if (d)
    st->data=GWEN_DB_Group_dup(d);
  else
    st->data=0;
  st->_modified=1;
}




AB_BANKING *AB_User_GetBanking(const AB_USER *st) {
  assert(st);
  return st->banking;
}


void AB_User_SetBanking(AB_USER *st, AB_BANKING *d) {
  assert(st);
  if (d)
    st->banking=d;
  else
    st->banking=0;
  st->_modified=1;
}




int AB_User_IsModified(const AB_USER *st) {
  assert(st);
  return st->_modified;
}


void AB_User_SetModified(AB_USER *st, int i) {
  assert(st);
  st->_modified=i;
}


void AB_User_Attach(AB_USER *st) {
  assert(st);
  st->_usage++;
}
AB_USER *AB_User_List2__freeAll_cb(AB_USER *st, void *user_data) {
  AB_User_free(st);
return 0;
}


void AB_User_List2_freeAll(AB_USER_LIST2 *stl) {
  if (stl) {
    AB_User_List2_ForEach(stl, AB_User_List2__freeAll_cb, 0);
    AB_User_List2_free(stl); 
  }
}




