#include "RemoteAppManager.h"


RemoteAppManager::RemoteAppManager(string appName)
{
	this->appName = appName;
	pythonAdapter = new PythonAdapter(appName);
	
	initFactories();
	
}


RemoteAppManager::~RemoteAppManager(void)
{
	delete itemFactory ;
	delete methodFactory;
	delete pythonAdapter;
	
}

AppOperation RemoteAppManager::translateOperation(string opp){
		OperationMap oppMap;
		oppMap["execute"] = Execute;
		oppMap["exit"] = Exit;

		return oppMap[opp];
}

void RemoteAppManager::initFactories(){
	ItemVector* items = pythonAdapter->getItemPrototypes();
	itemFactory = new ItemFactory();
	for(ItemVector::iterator it = items->begin(); it!= items->end(); ++it){
		itemFactory->registerItem((*it));
	}
	MethodVector* methods = pythonAdapter->getMethodPrototypes();
	methodFactory = new MethodFactory();
	for(MethodVector::iterator it = methods->begin(); it!= methods->end(); ++it){
		methodFactory->registerMethod((*it));
	}
	
}

void RemoteAppManager::start(){
	exit = false;
	//string text;
	cout <<endl << "-----< " << appName << " >----"<< endl;

	while(!exit) {
		cout << endl;
		printMethods();
		StringVector args = readConsoleStrings();
		string operation = args[0];

		switch (translateOperation(operation)){
		case Execute:
				exec(args);
			break;
		case Exit:
			exit = true;
			break;
		default:
			cout << endl << "incorrect command" << endl;
		} 

		cout << endl <<"u r welcome";
	}

}

void RemoteAppManager::printMethods(){
	StringVector* methods = methodFactory->getNames();
	cout << "	Available Methods: " << endl;
	for(StringVector::iterator it = methods->begin(); it!= methods->end(); ++it){
		cout << *it << endl;
	}
}


StringVector RemoteAppManager::readConsoleStrings() {
	string text;
	char ch= ' ';
	getline(cin,text);
	string next;
    StringVector result;
	 for (string::const_iterator it = text.begin(); it != text.end(); it++) {
        if (*it == ch) {
            if (!next.empty()) {
                result.push_back(next);
                next.clear();
            }
        } else {
			next += *it;
        }
    }
    if (!next.empty()){
         result.push_back(next);
	}
    return result;
}

void RemoteAppManager::exec(StringVector params){
	pythonAdapter->exec(params);
}