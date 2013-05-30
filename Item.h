#pragma once
#include <boost\unordered_map.hpp>
//prototype
using namespace std;

class Item
{
	typedef boost::unordered_map<string, string> ItemMap;

private:
	string name;
	ItemMap params;
public:
	Item(string name);
	Item(const Item& i);
	Item* clone() const;
	~Item(void);

	void setName(string name);
	string getName();
	void addParam(string key, string value="");
	string getParam(string key);
	ItemMap* getParams();
	string getParamNames();

	
};

