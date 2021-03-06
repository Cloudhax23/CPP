#include "stdafx.h"
#include <map>
#pragma once

class EventHandler
{
public:
	static std::multimap<char*, void*> EventsMap;
	static void AddEventHandler(char*, void*);
	template<typename T, typename ... Args >
	static void TriggerEventHandler(char* name, Args ... args);
};
