#ifndef SUBJECT
#define SUBJECT
#include <vector>
#include "Observer.hpp"

using namespace std;
class Observer;
class Subject
{
  vector <class Observer *> observers;

  public:
  void attach(Observer *obs);
  void notify(int type, void *t);
 };

#endif //SUBJECT
