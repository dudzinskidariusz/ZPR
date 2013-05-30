#pragma once
#include <boost/foreach.hpp>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include "JSONReader.h"
#include "ScriptManager.h"
#include "RemoteAppManager.h"


using namespace std;
//using namespace boost::python;
static enum FrontAppOperation { 
	Load, 
	Reload,
	ExitApp };

typedef vector<string> StringVector;
typedef boost::unordered_map<string, FrontAppOperation> FrontOperationMap;

class FrontEnd
{
private:
	FrontAppOperation translateOperation(string opp);
	vector<string> split(const string& str, const char& ch);
	void toLoad();
	vector<string> readConsoleStrings();
    void execLoad(string app);
	
	bool exit;
	ScriptManager* script;
	StringVector* scriptNames;
	RemoteAppManager* remoteAppManager;

public:
	FrontEnd(void);
	~FrontEnd(void);

	void start(string path);
};

