#pragma once
#include "ItemFactory.h"
#include "MethodFactory.h"
#include "PythonAdapter.h"
#include "JSONReader.h"

static enum AppOperation { 
	Execute, 
	Exit };

typedef vector<string> StringVector;
typedef boost::unordered_map<string, AppOperation> OperationMap;

class RemoteAppManager
{
private:
	void initFactories();
	vector<string> readConsoleStrings();
	void printMethods();
	AppOperation translateOperation(string opp);
	void exec(StringVector params);

	ItemFactory* itemFactory;
	MethodFactory* methodFactory;
	PythonAdapter* pythonAdapter;
	string appName;
	bool exit;

public:
	RemoteAppManager(string appName);
	~RemoteAppManager(void);

	void start();
};

