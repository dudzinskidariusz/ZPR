#include "remoteappmanager.h"


RemoteAppManager::RemoteAppManager(string appName)
{
	this->appName = appName;
	pythonAdapter = new PythonAdapter(appName);
	exit =false;
	initFactories();
	
}


RemoteAppManager::~RemoteAppManager(void)
{
	delete itemFactory ;
	delete methodFactory;
	delete pythonAdapter;
	delete authReq;
}

AppOperation RemoteAppManager::translateOperation(string opp){
		OperationMap oppMap;
		oppMap["execute"] = Execute;
		oppMap["exit"] = Exit;

		return oppMap[opp];
}

void RemoteAppManager::initFactories(){
	try{
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
	
		authReq = itemFactory->create("authentication");
		}catch(ScriptException &e){
			cout << e.getError() << endl;
			exit = true;
	}
}

void RemoteAppManager::start(){
	if(exit){
		cout << "exit is true";
		return;
	}
	exit = false;
	//string text;
	cout <<endl << "-----< " << appName << " >----"<< endl;
	cout << "User Credentials:" << endl;

	authentication();

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
void RemoteAppManager::authentication(){
	ItemMap* items = authReq->getParams();
	for(ItemMap::iterator it = items->begin(); it!= items->end(); ++it){
		cout << endl << (*it).first << ": ";
		StringVector s;
		s = readConsoleStrings();
		(*it).second=s[0];
	}
	for(ItemMap::iterator it = items->begin(); it!= items->end(); ++it){
		cout << endl << (*it).first << " : "<< (*it).second;
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
	cout << endl <<">";
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