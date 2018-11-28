/***************************************************************************
 begin       : Mon Nov 26 2018
 copyright   : (C) 2018 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 * This file is part of the project "AqBanking".                           *
 * Please see toplevel file COPYING of that project for license details.   *
 ***************************************************************************/


/*
 * This file is included by provider.c
 */



int AB_Provider_ReadUser(AB_PROVIDER *pro, uint32_t uid, int doLock, int doUnlock, AB_USER *user) {
  int rv;
  GWEN_DB_NODE *db=NULL;

  rv=AB_Banking_Read_UserConfig(AB_Provider_GetBanking(pro), uid, doLock, doUnlock, &db);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    return rv;
  }

  rv=AB_User_ReadFromDb(user, db);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    GWEN_DB_Group_free(db);
    return rv;
  }
  GWEN_DB_Group_free(db);

  return 0;
}



int AB_Provider_GetUser(AB_PROVIDER *pro, uint32_t uid, int doLock, int doUnlock, AB_USER **pUser) {
  int rv;
  AB_USER *u;

  u=AB_Provider_CreateUserObject(pro);
  assert(u);
  rv=AB_Provider_ReadUser(pro, uid, doLock, doUnlock, u);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    AB_User_free(u);
    return rv;
  }

  *pUser=u;

  return 0;
}



int AB_Provider_ReadUsers(AB_PROVIDER *pro, AB_USER_LIST *userList) {
  int rv;
  GWEN_DB_NODE *dbAll=NULL;
  GWEN_DB_NODE *db;

  /* read all config groups for users which have a unique id and which belong to AqHBCI */
  rv=AB_Banking_ReadConfigGroups(AB_Provider_GetBanking(pro), AB_CFG_GROUP_USERS, "uniqueId", "backendName", "AQHBCI", &dbAll);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    return rv;
  }

  db=GWEN_DB_GetFirstGroup(dbAll);
  while(db) {
    AB_USER *u=NULL;

    u=AB_Provider_CreateUserObject(pro);
    rv=AB_User_ReadFromDb(u, db);
    if (rv<0) {
      DBG_INFO(AQBANKING_LOGDOMAIN, "Error reading user (%d), ignoring", rv);
      AB_User_free(u);
    }
    else
      AB_User_List_Add(u, userList);

    /* next */
    db=GWEN_DB_GetNextGroup(db);
  }
  GWEN_DB_Group_free(dbAll);

  return 0;
}




int AB_Provider_WriteUser(AB_PROVIDER *pro, uint32_t uid, int doLock, int doUnlock, const AB_USER *user) {
  int rv;
  GWEN_DB_NODE *db;

  db=GWEN_DB_Group_new("user");
  rv=AB_User_WriteToDb(user, db);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    return rv;
  }

  rv=AB_Banking_Write_UserConfig(AB_Provider_GetBanking(pro), uid, doLock, doUnlock, db);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    GWEN_DB_Group_free(db);
    return rv;
  }
  GWEN_DB_Group_free(db);

  return 0;
}



int AB_Provider_BeginExclUseUser(AB_PROVIDER *pro, AB_USER *u) {
  int rv;
  uint32_t uid;

  uid=AB_User_GetUniqueId(u);
  if (uid==0) {
    DBG_ERROR(AQBANKING_LOGDOMAIN, "No unique id!");
    return GWEN_ERROR_INVALID;
  }
  rv=AB_Provider_ReadUser(pro, uid, 1, 0, u);
  if (rv<0) {
    DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
    return rv;
  }
  return 0;
}



int AB_Provider_EndExclUseUser(AB_PROVIDER *pro, AB_USER *u, int abandon) {
  int rv;
  uint32_t uid;

  uid=AB_User_GetUniqueId(u);
  if (uid==0) {
    DBG_ERROR(AQBANKING_LOGDOMAIN, "No unique id!");
    return GWEN_ERROR_INVALID;
  }

  if (abandon) {
    rv=AB_Banking_Unlock_UserConfig(AB_Provider_GetBanking(pro), uid);
    if (rv<0) {
      DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
      return rv;
    }
  }
  else {
    rv=AB_Provider_WriteUser(pro, uid, 0, 1, u);
    if (rv<0) {
      DBG_INFO(AQBANKING_LOGDOMAIN, "here (%d)", rv);
      return rv;
    }
  }

  return 0;
}



