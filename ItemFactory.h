#pragma once
#include "Item.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Item*> ItemsMap;

class ItemFactory
{
private:
	ItemsMap* items;
public:
	ItemFactory(void);
	~ItemFactory(void);

	bool registerItem(Item* item);
	Item* create(string name);
};

