#ifndef RESULT_MSG_H
#define RESULT_MSG_H

#define R_ADD_MSG 0
#define QUIT_MSG 1

#include "CLMessage.h"

class CLResultAddMsg : public CLMessage {
 public:
 CLResultAddMsg():CLMessage(R_ADD_MSG){}
  ~CLResultAddMsg(){}
};

class CLResultQuitMsg : public CLMessage {
 public:
 CLResultQuitMsg():CLMessage(QUIT_MSG){}
 ~CLResultQuitMsg(){}
};

#endif
