#include "item.h"
#include <boost/unordered_map.hpp>

Item::Item(string name){
	this->name = name;
	//params;
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

