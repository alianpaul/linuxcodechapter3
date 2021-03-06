#include "CLMainMsgProcessor.h"
#include "CustomMsg.h"
#include "ResultMsg.h"
#include "CLMessageLoopManager.h"
#include <iostream>
#include <unistd.h>
#include "CLExecutiveNameServer.h"

CLMainMsgProcessor :: CLMainMsgProcessor(){

}

CLMainMsgProcessor :: ~CLMainMsgProcessor(){

}

CLStatus CLMainMsgProcessor :: Initialize(CLMessageLoopManager * pMsgLoopManager, void* pContext) {
  pMsgLoopManager->Register(R_ADD_MSG, (CallBackForMessageLoop)(&CLMainMsgProcessor::On_R_Add));
  pMsgLoopManager->Register(QUIT_MSG, (CallBackForMessageLoop)(&CLMainMsgProcessor::On_R_Quit));
  return CLStatus(0, 0);
}

CLStatus CLMainMsgProcessor :: On_R_Add(CLMessage * pMessage) {
  std::cout << "mainprocessor : R_Add Message Rcv" << std::endl;
  return CLStatus(R_ADD_MSG, 0);
}

CLStatus CLMainMsgProcessor :: On_R_Quit(CLMessage * pMessage) {
  std::cout << "mainprocessror : R_Quit Message Rcv" << std::endl;
  return CLStatus(QUIT_MSG, 0);
}

