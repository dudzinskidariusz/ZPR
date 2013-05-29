#include "MethodFactory.h"
#include "Method.h"
#include <boost\unordered_map.hpp>

using namespace std;
/*
typedef boost::unordered_map<string, Method> Methods_map;

MethodFactory::MethodFactory(void){
	methods = new Methods_map();
}

MethodFactory::~MethodFactory(void){
	delete methods;
}

bool MethodFactory::registerMethod(Method* Method){
	methods->insert(make_pair(&(Method->getName()), &Method));
}

Method* MethodFactory::create(string name){
	return methods->find(name)->second.clone();
}*/