#include "Engine.h"

Engine::Engine(unsigned id0, const char* brand0, const char* description0, size_t horsePower0) :
	CarPart(id0, brand0, description0), hoursePower(horsePower0) {}
