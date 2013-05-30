#pragma once
#include "Method.h"
#include "iostream"
#include <vector>
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Method*> MethodsMap;
typedef vector<string> StringVector;

class MethodFactory{
private:
	MethodsMap* methods;
public:
	MethodFactory(void);
	~MethodFactory(void);

	bool registerMethod(Method* method);
	Method* create(string name);
	StringVector* getNames();
};

