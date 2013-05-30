#include "Method.h"
#include <boost/unordered_map.hpp>

typedef boost::unordered_map<string, Item*> MethodMap;

Method::Method(string name){
	this->name = name;
	params;
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

string Method::getParamNames(){
	string names;
	for(boost::unordered_map<string, Item*>::iterator it =params.begin();it != params.end(); ++it){
		names = " " + it->first + " ";
	}
	return names;
}