#include <iostream>
#include <unistd.h>
#include "libexe.h"
#include "CustomMsg.h"
#include "CLMyMsgProcessor.h"
#include "CLMainMsgProcessor.h"

using namespace std;

int main(){

  CLThreadForMsgLoop tMyProcessor(new CLMyMsgProcessor, "myprocessor", true);
  tMyProcessor.Run();
  cout << "main push to myprocessor" << endl;
  CLExecutiveNameServer::PostExecutiveMessage("myprocessor",new CLAddMsg);
  cout << "main push to myprocessor" << endl;
  CLExecutiveNameServer::PostExecutiveMessage("myprocessor", new CLAddMsg);
   cout << "main push to myprocessor" << endl;
  CLExecutiveNameServer::PostExecutiveMessage("myprocessor", new CLQuitMsg);
    
  CLNonThreadForMsgLoop tMain(new CLMainMsgProcessor, "main");
  tMain.Run();
  
}

