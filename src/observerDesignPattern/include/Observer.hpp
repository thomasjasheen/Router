#ifndef OBSERVER
#define OBSERVER
#include <vector>
#include "Observer.hpp"
#include "Subject.hpp"
class Observer
{
 //TODO make it a vector or an array
 Subject *subs;

 public:
  //TODO add code to get an array
  Observer (Subject *sub);
  virtual int update(int type, void *t) = 0;
};
#endif //OBSERVER
