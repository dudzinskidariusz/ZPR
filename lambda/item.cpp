#include "item.h"
#include <boost/unordered_map.hpp>

typedef vector<string> StringVector;

Item::Item(string name){
	this->name = name;
}

Item* Item::clone() const{
	return new Item(*this);
}

Item::Item(const Item& i){
	name = i.name;
	params = i.params;
}
Item::~Item(void){
	//delete params;
}

void Item::setName(string name){
	this->name = name;
}

string Item::getName(){
	return name;
}

void Item::addParam(string key, string value){
	params[key]=value;
}

string Item::getParam(string key){
	return params[key];
}

boost::unordered_map<string, string>* Item::getParams(){
	return &params;
}

StringVector* Item::getNames(){
	StringVector* stringVector = new StringVector();
	for(ItemMap::iterator it = params.begin(); it!= params.end(); ++it){
		stringVector->push_back(it->first);
	}
	return stringVector;
}