#pragma once
#include "lambda\remoteappmanager.h"
#include <vector>

class PMappTest :public RemoteAppManager
{
public:
	PMappTest(void) :RemoteAppManager("Test"){};
	~PMappTest(void) {};

	bool readScriptTest();
	ItemFactory* getMethodFactory();
	ItemFactory* getItemFactory();
};

