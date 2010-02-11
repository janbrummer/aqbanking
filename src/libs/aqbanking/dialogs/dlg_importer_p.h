/***************************************************************************
 begin       : Tue Feb 10 2010
 copyright   : (C) 2010 by Martin Preuss
 email       : martin@aqbanking.de

 ***************************************************************************
 * This file is part of the project "AqBanking".                           *
 * Please see toplevel file COPYING of that project for license details.   *
 ***************************************************************************/

#ifndef AQBANKING_DLG_IMPORTER_P_H
#define AQBANKING_DLG_IMPORTER_P_H

#include "dlg_importer.h"


#include <gwenhywfar/stringlist.h>


typedef struct AB_IMPORTER_DIALOG AB_IMPORTER_DIALOG;
struct AB_IMPORTER_DIALOG {
  AB_BANKING *banking;
  AB_IMEXPORTER_CONTEXT *context;

  char *fileName;
  char *importerName;
  char *profileName;
  GWEN_DB_NODE *dbParams;

};


GWENHYWFAR_CB void AB_ImporterDialog_FreeData(void *bp, void *p);

const char *AB_ImporterDialog_GetFileName(const GWEN_DIALOG *dlg);
void AB_ImporterDialog_SetFileName(GWEN_DIALOG *dlg, const char *s);

const char *AB_ImporterDialog_GetImporterName(const GWEN_DIALOG *dlg);
void AB_ImporterDialog_SetImporterName(GWEN_DIALOG *dlg, const char *s);

const char *AB_ImporterDialog_GetProfileName(const GWEN_DIALOG *dlg);
void AB_ImporterDialog_SetProfileName(GWEN_DIALOG *dlg, const char *s);


GWENHYWFAR_CB int AB_ImporterDialog_SignalHandler(GWEN_DIALOG *dlg,
						  GWEN_DIALOG_EVENTTYPE t,
						  const char *sender,
						  int intVal,
						  const char *charVal,
						  void *ptrVal);


#endif

