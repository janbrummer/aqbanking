/* This file is auto-generated from "transaction.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef TRANSACTION_P_H
#define TRANSACTION_P_H

#include "transaction_l.h"


struct AB_TRANSACTION {
  GWEN_INHERIT_ELEMENT(AB_TRANSACTION)
  GWEN_LIST_ELEMENT(AB_TRANSACTION)
  int _usage;
  int _modified;

  char *localCountry;
  char *localBankCode;
  char *localBranchId;
  char *localAccountNumber;
  char *localSuffix;
  char *localIban;
  char *localName;
  char *remoteCountry;
  char *remoteBankName;
  char *remoteBankLocation;
  char *remoteBankCode;
  char *remoteBranchId;
  char *remoteAccountNumber;
  char *remoteSuffix;
  char *remoteIban;
  GWEN_STRINGLIST *remoteName;
  uint32_t uniqueId;
  GWEN_TIME *valutaDate;
  GWEN_TIME *date;
  AB_VALUE *value;
  AB_VALUE *fees;
  int textKey;
  char *transactionKey;
  char *customerReference;
  char *bankReference;
  int transactionCode;
  char *transactionText;
  char *primanota;
  char *fiId;
  GWEN_STRINGLIST *purpose;
  GWEN_STRINGLIST *category;
  AB_TRANSACTION_PERIOD period;
  int cycle;
  int executionDay;
  GWEN_TIME *firstExecutionDate;
  GWEN_TIME *lastExecutionDate;
  GWEN_TIME *nextExecutionDate;
  AB_TRANSACTION_TYPE type;
  AB_TRANSACTION_SUBTYPE subType;
  AB_TRANSACTION_STATUS status;
  AB_TRANSACTION_CHARGE charge;
  char *remoteAddrStreet;
  char *remoteAddrZipcode;
  char *remoteAddrCity;
  char *remotePhone;
  int units;
  AB_VALUE *unitPrice;
};




/** @name Local Account Info
 *
This group contains information about the local account.*/
/*@{*/








/*@}*/

/** @name Remote Account Info
 *
This group contains information about the remote account.*/
/*@{*/










/*@}*/


/** @name Dates
*/
/*@{*/


/*@}*/

/** @name Value
 *
*/
/*@{*/


/*@}*/


/** @name Info Which Is Not Supported by All Backends
 *
<p>This group contains information which differ between backends.</p>
<p>
  Some of this information might not even be<b>supported</b>
  by every backends.</p>*/
/*@{*/











/*@}*/

/** @name Additional Information for Standing Orders
 *
<p>This group contains information which is used with standing orders. It is not needed for other usage of this type.</p>*/
/*@{*/







/*@}*/

/** @name Additional Information for Transfers
 *
<p>This group contains information which is used with all kinds of transfers. It is setup by the function @ref AB_Banking_GatherResponses for transfers but not used by AqBanking otherwise.</p>*/
/*@{*/





/*@}*/

/** @name Additional Information for Foreign Transfers
 *
<p>This group contains information which is used with transfers to other countries in the world. It is used by backends and applications but not by AqBanking itself.</p>*/
/*@{*/





/*@}*/

/** @name Additional Information for Investment Transfers
 *
<p>This group contains information which is used with investment/stock transfers. It is used by backends and applications but not by AqBanking itself.</p>*/
/*@{*/



/*@}*/


#endif /* TRANSACTION_P_H */
