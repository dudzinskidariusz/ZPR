#include "Method.h"
#include <boost/unordered_map.hpp>

typedef boost::unordered_map<string, Item*> map;

Method::Method(void){
	this->name = name;
	//params;
}

Method* Method::clone() const{
	return new Method(*this);
}

Method::Method(const Method& m){
	name=m.name;
	params=m.params;
}


Method::~Method(void){
	//delete params;
}

void Method::setName(string name){
	this->name = name;
}

string Method::getName(){
	return name;
}

void Method::addParam(string key, Item* value){
	params[key]=value;
}

Item* Method::getParam(string key){
	return params[key];
}

boost::unordered_map<string, Item*>* Method::getParams(){
	return &params;
}