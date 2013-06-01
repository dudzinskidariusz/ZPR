#pragma once
#include "StdAfx.h"
#include "PMappTest.h"

typedef vector<string> StringVector;

ItemFactory* PMappTest::getMethodFactory(){
	return methodFactory;
}
ItemFactory* PMappTest::getItemFactory(){
	return itemFactory;
}

