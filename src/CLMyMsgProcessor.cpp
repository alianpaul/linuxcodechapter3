#include "CLMyMsgProcessor.h"
#include "CustomMsg.h"
#include "ResultMsg.h"
#include "CLMessageLoopManager.h"
#include <iostream>
#include <unistd.h>
#include "CLExecutiveNameServer.h"

CLMyMsgProcessor :: CLMyMsgProcessor(){

}

CLMyMsgProcessor :: ~CLMyMsgProcessor(){

}

CLStatus CLMyMsgProcessor :: Initialize(CLMessageLoopManager * pMsgLoopManager, void* pContext) {
  pMsgLoopManager->Register(ADD_MSG, (CallBackForMessageLoop)(&CLMyMsgProcessor::On_Add));
  pMsgLoopManager->Register(QUIT_MSG, (CallBackForMessageLoop)(&CLMyMsgProcessor::On_Quit));
  return CLStatus(0, 0);
}

CLStatus CLMyMsgProcessor :: On_Add(CLMessage * pMessage) {
  std::cout << "myprocessor : Add Message Rcv" << std::endl;
  sleep(1);
  std::cout << "myprocessor push to main" << std::endl;
  CLExecutiveNameServer :: PostExecutiveMessage("main", new CLResultAddMsg);
  return CLStatus(ADD_MSG, 0);
}

CLStatus CLMyMsgProcessor :: On_Quit(CLMessage * pMessage) {
  std::cout << "myprocessror : Quit Message Rcv" << std::endl;
   std::cout << "myprocessror push to  main" << std::endl;
  CLExecutiveNameServer :: PostExecutiveMessage("main", new CLResultQuitMsg);
  return CLStatus(QUIT_MSG, 0);
}


