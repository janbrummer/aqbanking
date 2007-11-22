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

#ifndef AO_PROVIDER_P_H
#define AO_PROVIDER_P_H


#define AO_PROVIDER_CONNECT_TIMEOUT 15
#define AO_PROVIDER_SEND_TIMEOUT    10
#define AO_PROVIDER_RECV_TIMEOUT    60

#include "queues_l.h"
#include "context_l.h"
#include <aqofxconnect/provider.h>
#include <aqbanking/transaction.h>
#include <gwenhywfar/buffer.h>



struct AO_PROVIDER {
  GWEN_DB_NODE *dbConfig;

  int connectTimeout;
  int sendTimeout;
  int recvTimeout;
  uint32_t lastJobId;

  AO_QUEUE *queue;
  AB_JOB_LIST2 *bankingJobs;
};

static void GWENHYWFAR_CB AO_Provider_FreeData(void *bp, void *p);

static int AO_Provider_Init(AB_PROVIDER *pro, GWEN_DB_NODE *dbData);
static int AO_Provider_Fini(AB_PROVIDER *pro, GWEN_DB_NODE *dbData);
static int AO_Provider_UpdateJob(AB_PROVIDER *pro, AB_JOB *j, uint32_t guiid);
static int AO_Provider_AddJob(AB_PROVIDER *pro, AB_JOB *j, uint32_t guiid);
static int AO_Provider_Execute(AB_PROVIDER *pro,
			       AB_IMEXPORTER_CONTEXT *ctx,
			       uint32_t guiid);
static int AO_Provider_ResetQueue(AB_PROVIDER *pro);
static int AO_Provider_ExtendUser(AB_PROVIDER *pro, AB_USER *u,
                                  AB_PROVIDER_EXTEND_MODE em);
static int AO_Provider_ExtendAccount(AB_PROVIDER *pro, AB_ACCOUNT *a,
                                     AB_PROVIDER_EXTEND_MODE em);


#if 0
static int AO_Provider_EncodeJob(AB_PROVIDER *pro,
                                 AO_CONTEXT *ctx,
                                 char **pData);
#endif

static int AO_Provider_SendAndReceive(AB_PROVIDER *pro,
                                      AB_USER *u,
				      const uint8_t *p,
                                      unsigned int plen,
				      GWEN_BUFFER **rbuf,
				      uint32_t guiid);

static int AO_Provider_RequestStatements(AB_PROVIDER *pro, AB_JOB *j,
					 AB_IMEXPORTER_CONTEXT *ictx,
					 uint32_t guiid);

static int AO_Provider_ExecUserQueue(AB_PROVIDER *pro,
				     AB_IMEXPORTER_CONTEXT *ctx,
				     AO_USERQUEUE *uq,
				     uint32_t guiid);
static int AO_Provider_ExecQueue(AB_PROVIDER *pro,
				 AB_IMEXPORTER_CONTEXT *ctx,
				 uint32_t guiid);

static int AO_Provider_CountDoneJobs(AB_JOB_LIST2 *jl);
static AB_JOB *AO_Provider_FindJobById(AB_JOB_LIST2 *jl, uint32_t jid);




#endif

