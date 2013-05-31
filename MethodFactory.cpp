#include "methodfactory.h"

#include <boost\unordered_map.hpp>

typedef boost::unordered_map<string, Method*> MethodsMap;
typedef vector<string> StringVector;

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

StringVector* MethodFactory::getNames(){
	StringVector* stringVector = new StringVector();
	for(MethodsMap::iterator it = methods->begin(); it!= methods->end(); ++it){
		stringVector->push_back(it->first);
	}
	return stringVector;
}