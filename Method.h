#pragma once
#include <boost\unordered_map.hpp>
#include "Item.h"
//prototype
using namespace std;

class Method
{
	typedef boost::unordered_map<string, Item*> MethodMap;
private:
	string name;
	MethodMap params;
public:
	Method(string name);
	Method(const Method& i);
	Method* clone() const;
	~Method(void);

	bool Execute();
	void setName(string name);
	string getName();
	void addParam(string key, Item* value = 0);
	Item* getParam(string key);
	MethodMap* getParams();
	string getParamNames();
	struct name_hash  
    { 
       size_t operator() (std::string* name)
       {
           std::hash<std::string> h;
           return h(*name);
       }
    };
};

