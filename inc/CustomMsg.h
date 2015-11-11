#ifndef CUSTOM_MSG_H
#define CUSTOM_MSG_H

#define ADD_MSG 0
#define QUIT_MSG 1

#include "CLMessage.h"

class CLAddMsg : public CLMessage {
public:
  CLAddMsg() : CLMessage(ADD_MSG){};
  ~CLAddMsg(){}
};

class CLQuitMsg : public CLMessage {
public:
  CLQuitMsg() : CLMessage(QUIT_MSG){};
  ~CLQuitMsg(){};
};
#endif
