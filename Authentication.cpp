#include "Authentication.h"


Authentication::Authentication(void)
{
}


Authentication::~Authentication(void)
{
}

void Authentication::setName(string name){
	this->name = name;
}

string Authentication::getName(){
	return name;
}

void Authentication::addParam(string key, string value){
	params[key]=value;
}

string Authentication::getParam(string key){
	return params[key];
}

boost::unordered_map<string, string>* Authentication::getParams(){
	return &params;
}

string Authentication::getParamNames(){
	string names;
	for(boost::unordered_map<string, string>::iterator it =params.begin();it != params.end(); ++it){
		names = " " + it->first + " ";
	}
	return names;

}
