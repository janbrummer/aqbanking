/***************************************************************************
 $RCSfile$
 -------------------
 cvs         : $Id$
 begin       : Mon Mar 01 2004
 copyright   : (C) 2004 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/


#ifndef AQBANKING_ACCOUNT_H
#define AQBANKING_ACCOUNT_H

#include <gwenhywfar/misc.h>
#include <gwenhywfar/misc2.h>
#include <gwenhywfar/inherit.h>
#include <gwenhywfar/types.h>
#include <gwenhywfar/db.h>

typedef struct AB_ACCOUNT AB_ACCOUNT;
GWEN_INHERIT_FUNCTION_DEFS(AB_ACCOUNT);
GWEN_LIST2_FUNCTION_DEFS(AB_ACCOUNT, AB_Account);

#include <aqbanking/banking.h>
#include <aqbanking/provider.h>
#include <aqbanking/job.h>


AB_ACCOUNT *AB_Account_new(AB_BANKING *ab,
                           AB_PROVIDER *pro,
                           const char *idForProvider);
void AB_Account_free(AB_ACCOUNT *acc);

int AB_Account_CheckAvailability(AB_ACCOUNT *a);

GWEN_TYPE_UINT32 AB_Account_GetUniqueId(const AB_ACCOUNT *acc);
void AB_Account_SetUniqueId(AB_ACCOUNT *acc, GWEN_TYPE_UINT32 id);

AB_PROVIDER *AB_Account_GetProvider(const AB_ACCOUNT *acc);

GWEN_DB_NODE *AB_Account_GetAppData(const AB_ACCOUNT *acc);
GWEN_DB_NODE *AB_Account_GetProviderData(const AB_ACCOUNT *acc);

const char *AB_Account_GetAccountNumber(const AB_ACCOUNT *acc);
void AB_Account_SetAccountNumber(AB_ACCOUNT *acc, const char *s);

const char *AB_Account_GetBankCode(const AB_ACCOUNT *acc);
void AB_Account_SetBankCode(AB_ACCOUNT *acc, const char *s);

const char *AB_Account_GetAccountName(const AB_ACCOUNT *acc);
void AB_Account_SetAccountName(AB_ACCOUNT *acc, const char *s);

const char *AB_Account_GetBankName(const AB_ACCOUNT *acc);
void AB_Account_SetBankName(AB_ACCOUNT *acc, const char *s);

const char *AB_Account_GetOwnerName(const AB_ACCOUNT *acc);
void AB_Account_SetOwnerName(AB_ACCOUNT *acc, const char *s);



#endif /* AQBANKING_ACCOUNT_H */
