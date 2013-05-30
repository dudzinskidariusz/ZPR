#include "MethodFactory.h"
#include "Method.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Method*> MethodsMap;

MethodFactory::MethodFactory(void){
	methods = new MethodsMap();
}

MethodFactory::~MethodFactory(void){
	delete methods;
}

bool MethodFactory::registerMethod(Method* method){
	string name = method->getName();
	methods->emplace(name,method);
	return true;
}

Method* MethodFactory::create(string name){
	return methods->find(name)->second->clone();
}