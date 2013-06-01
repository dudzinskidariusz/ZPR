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
	delete auth;
}

AppOperation RemoteAppManager::translateOperation(string opp){
		OperationMap oppMap;
		oppMap[""] = Wrong;
		oppMap["execute"] = Execute;
		oppMap["exit"] = Exit;

		return oppMap[opp];
}

void RemoteAppManager::initFactories(){
	try{
		ItemVector* items = pythonAdapter->getItemPrototypes("items");
		itemFactory = new ItemFactory();
		for(ItemVector::iterator it = items->begin(); it!= items->end(); ++it){
			itemFactory->registerItem((*it));
		}
		ItemVector* methods = pythonAdapter->getItemPrototypes("methods");
		methodFactory = new ItemFactory();
		for(ItemVector::iterator it = methods->begin(); it!= methods->end(); ++it){
			methodFactory->registerItem((*it));
		}
	
		auth = itemFactory->create("authentication");
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

	auth = createItem("item", "authentication");

	while(!exit) {
		cout << endl;
		printMethods();
		StringVector args = readConsoleStrings();
		string operation = args[0];
		switch (translateOperation(operation)){
		case Execute:
			exec();
			break;
		case Exit:
			exit = true;
			break;
		default:
			cout << endl << "incorrect command" << endl;
		} 
	}

}

Item* RemoteAppManager::createItem(string type, string name){
	
	ItemFactory* factory;
	if(type=="method"){
		factory = methodFactory;
	}else if(type=="item"){
		factory = itemFactory;
	}

	Item* item = factory->create(name);
	ItemMap* params = item->getParams();
	bool isNull =true;
	for(ItemMap::iterator it = params->begin(); it!= params->end(); ++it){
		isNull=true;
		while(isNull){
			cout << endl << (*it).first << ": ";
			StringVector s;
			s = readConsoleStrings();
			if(s.size()==0){
				isNull=true;
			}else{
				(*it).second=s[0];
				isNull=false;
			}
		}
	}
	return item;
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

void RemoteAppManager::exec(){
	
	cout << endl << "type method: ";
	StringVector s = readConsoleStrings();
	StringVector* methods = methodFactory->getNames();
	cout << "	Parameters: " << endl;
	for(StringVector::iterator it = methods->begin(); it!= methods->end(); ++it){
		if(s[0]==*it){
			Item* method = createItem("method", s[0]);
			pythonAdapter->exec(method);
			return;
		}
	}

	cout << "there is no such method" <<endl;
	
}