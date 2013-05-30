#pragma once
#include "ItemFactory.h"
#include "MethodFactory.h"
#include "PythonAdapter.h"
#include "JSONReader.h"
#include "ScriptException.h"

static enum AppOperation { 
	Execute, 
	Exit };

typedef vector<string> StringVector;
typedef boost::unordered_map<string, AppOperation> OperationMap;
typedef boost::unordered_map<string, string> ItemMap;

class RemoteAppManager
{
private:
	void initFactories();
	vector<string> readConsoleStrings();
	void printMethods();
	AppOperation translateOperation(string opp);
	void exec(StringVector params);
	void authentication();

	ItemFactory* itemFactory;
	MethodFactory* methodFactory;
	PythonAdapter* pythonAdapter;
	Item* authReq;
	string appName;
	bool exit;

public:
	RemoteAppManager(string appName);
	~RemoteAppManager(void);

	void start();
};

