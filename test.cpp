#include "EventHandler.h"

int testing(int x)
{
 std::cout << std::endl << x; // will print 1
 return 0;
}

typedef int(testingDef)(int); // for our void*

int main()
{
  EventHandler::AddEventHandler("hi", testing);
  EventHandler::TriggerEventHandler<testingDef, int>("hi", 1); // find the Event(s) named "hi" pass a value of 1 as in the input for the function.
  
  return 0;
}
