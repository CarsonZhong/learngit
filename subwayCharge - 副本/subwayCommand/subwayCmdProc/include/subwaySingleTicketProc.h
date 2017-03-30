﻿#ifndef __CMD_SINGLE_TICKET_PROC_H__
#define __CMD_SINGLE_TICKET_PROC_H__
#include "subwayGlobalDef.h"
#include "subwayCmdParse/subwayCmdParse.h"

/*
@ 办理单程票
@ 入参：unCmd, 命令内容
@ 出参: returnStr
@ 返回值: 无
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH]);

#endif
