#pragma once
#include "ItemFactory.h"
#include "MethodFactory.h"
#include "PythonAdapter.h"

class AgileManager
{
private:
	//ItemFactory* itemFactory;
	//MethodFactory* methidFactory;
	PythonAdapter* pythonAdapter;

public:
	AgileManager(void);
	~AgileManager(void);
};

