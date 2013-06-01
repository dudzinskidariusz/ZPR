#include "itemfactory.h"
#include "item.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Item*> ItemsMap;
typedef vector<string> StringVector;

ItemFactory::ItemFactory(void){
	items = new ItemsMap();
}

ItemFactory::~ItemFactory(void){
	delete items;
}

bool ItemFactory::registerItem(Item* item){
	string name = item->getName();
	items->emplace(name, item);
	return true;
}

Item* ItemFactory::create(string name){
	return items->find(name)->second->clone();
}

StringVector* ItemFactory::getNames(){
	StringVector* stringVector = new StringVector();
	for(ItemsMap::iterator it = items->begin(); it!= items->end(); ++it){
		stringVector->push_back(it->first);
	}
	return stringVector;
}