#pragma once
#include <boost\unordered_map.hpp>
//prototype
using namespace std;

class Item
{
	typedef boost::unordered_map<string, string> map;

private:
	string name;
	map params;
public:
	Item(string name);
	Item(const Item& i);
	Item* clone() const;
	~Item(void);

	void setName(string name);
	string getName();
	void addParam(string key, string value);
	string getParam(string key);
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

