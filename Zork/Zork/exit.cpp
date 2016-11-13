#include "exit.h"



Exit::Exit(const char* name, const char* description, Room* source, Room* destination):
Entity(name, description), source(source), destination(destination)
{
	type = EXIT;
}


Exit::~Exit()
{
}
