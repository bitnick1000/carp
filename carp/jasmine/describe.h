#ifndef __DESCRIBE_H__
#define __DESCRIBE_H__
#include "spec.h"
#include "jasmine.h"
#include <iostream>

#define func []
typedef void (*fp)();

void Describe(std::string description,fp f){
	spec.LevelUp();
	spec.AddApec(description,FunctionType::Describe);
	f();
	spec.LevelDown();
	if (spec.GetLevel()==0){
		spec.Print();
	}
}
void It(std::string description,fp f){
	spec.LevelUp();
	spec.AddApec(description,FunctionType::It);
	f();
	spec.LevelDown();
}

#endif