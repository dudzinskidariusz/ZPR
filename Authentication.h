#pragma once
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, string> AuthMap;

class Authentication
{
private:
	string name;
	AuthMap params;
public:
	Authentication(void);
	~Authentication(void);

	void setName(string name);
	string getName();
	void addParam(string key, string value="");
	string getParam(string key);
	AuthMap* getParams();
	string getParamNames();
};

