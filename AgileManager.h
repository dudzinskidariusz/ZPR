#pragma once
#include "ItemFactory.h"
#include "MethodFactory.h"
#include "PythonAdapter.h"
#include "JSONReader.h"

class AgileManager
{
private:
	ItemFactory* itemFactory;
	MethodFactory* methodFactory;
	PythonAdapter* pythonAdapter;
	JSONReader* jsonReader;

public:
	AgileManager(void);
	~AgileManager(void);
};

