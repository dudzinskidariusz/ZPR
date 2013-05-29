#pragma once
#include <boost\unordered_map.hpp>
#include "Item.h"
//prototype
using namespace std;

class Method
{
	typedef boost::unordered_map<string, Item*> map;
private:
	string name;
	map params;
public:
	Method(void);
	Method(const Method& i);
	Method* clone() const;
	~Method(void);

	bool Execute();
	void setName(string name);
	string getName();
	void addParam(string key, Item* value);
	Item* getParam(string key);
	map* getParams();
	struct name_hash  
    { 
       size_t operator() (std::string* name)
       {
           std::hash<std::string> h;
           return h(*name);
       }
    };
};

