
#include "ItemFactory.h"
#include "Item.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Item*> ItemsMap;

ItemFactory::ItemFactory(void){
	items = new ItemsMap();
}

ItemFactory::~ItemFactory(void){
	delete items;
}

bool ItemFactory::registerItem(Item* item){
	string name = item->getName();
	items->emplace(name, item);
	//items->insert(make_pair(&(item->getName()), &item));
	return true;
}

Item* ItemFactory::create(string name){
	return items->find(name)->second->clone();
}