#include "stdafx.h"
#include "EventHandler.h"
#include <map>

std::multimap<char*, void*> EventHandler::EventsMap;

void EventHandler::AddEventHandler(char* name, void* func)
{
	EventsMap.insert(std::pair<char*, void*>(name, func));
}

template<typename T, typename ... Args >
void EventHandler::TriggerEventHandler(char* name, Args ... args)
{
	std::pair<std::multimap<char*, void*>::iterator, std::multimap<char*, void*>::iterator> mapIterator;
	mapIterator = EventsMap.equal_range(name);
	for (std::multimap<char*, void*>::iterator eventIterator = mapIterator.first; eventIterator != mapIterator.second; ++eventIterator)
	{
		((T*)((*eventIterator).second)) (args...);
	}
};
