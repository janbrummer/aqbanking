/***************************************************************************
 begin       : Mon Mar 01 2004
 copyright   : (C) 2004-2013 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 * This file is part of the project "AqBanking".                           *
 * Please see toplevel file COPYING of that project for license details.   *
 ***************************************************************************/


#ifndef AQBANKING_JOBINTERNALTRANSFER_L_H
#define AQBANKING_JOBINTERNALTRANSFER_L_H


#include <aqbanking/jobinternaltransfer_be.h>


AB_JOB *AB_JobInternalTransfer_fromDb(AB_ACCOUNT *a, GWEN_DB_NODE *db);
int AB_JobInternalTransfer_toDb(const AB_JOB *j, GWEN_DB_NODE *db);


#endif

