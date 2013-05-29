/*
#include "ItemFactory.h"
#include "Item.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Item*> items_map;

ItemFactory::ItemFactory(void){
	items = new items_map();
}

ItemFactory::~ItemFactory(void){
	delete items;
}

bool ItemFactory::registerItem(Item* item){
	items->insert(make_pair(&(item->getName()), &item));
}

Item* ItemFactory::create(string name){
	return items->find(name)->second->clone();
}*/