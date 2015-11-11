#ifndef CL_MAIN_MSG_PROCESSOR_H
#define CL_MAIN_MSG_PROCESSOR_H

#include "CLStatus.h"
#include "CLMessage.h"
#include "CLMessageObserver.h"
#include "CLMessageLoopManager.h"

class CLMainMsgProcessor : public CLMessageObserver {
 public:
  CLMainMsgProcessor();
  ~CLMainMsgProcessor();

  CLStatus Initialize(CLMessageLoopManager * pMsgLoopManager, void * pContext);

  CLStatus On_R_Add(CLMessage * pMessage);

  CLStatus On_R_Quit(CLMessage * pMessage);
  
};

#endif
