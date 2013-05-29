#pragma once
#include "Method.h"
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Method> Methods_map;

class MethodFactory{
private:
	Methods_map* methods;
public:
	MethodFactory(void);
	~MethodFactory(void);

	bool registerMethod(Method* method);
	Method* create(string name);
};

