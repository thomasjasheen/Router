#include "./include/Observer.hpp"
#include "./include/Subject.hpp"

using namespace std;

  //TODO add code to get an array
  Observer::Observer (Subject *sub)
  {
   subs =  sub;
   subs->attach(this);
  }
  
