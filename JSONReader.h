#pragma once
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include "json.h"

using namespace Json;

typedef vector<Item*> ItemVector;
typedef vector<Method*> MethodVector;

class JSONReader
{

public:
	JSONReader(void);
	~JSONReader(void);

	ItemVector* readItems(string itemString);
	string writeItems(ItemVector* vector);
	Item* readItem(Value value);
	MethodVector* readMethods(string itemString);
	string writeMethods(MethodVector* vector);
	Method* readMethod(Value value);
};

