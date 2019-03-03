#include <vector>
#include "./include/Observer.hpp"
#include "./include/Subject.hpp"

using namespace std;

  void Subject::attach(Observer *obs)
  {
   observers.push_back(obs);
  }

  void Subject::notify(int type, void *t)
  {
   for(int i=0; i < observers.size(); i++)
    observers[i]->update(type, t);
  }
