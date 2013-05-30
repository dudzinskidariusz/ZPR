#include "FrontEnd.h"


FrontEnd::FrontEnd(void)
{
}


FrontEnd::~FrontEnd(void)
{
	delete script;
	delete scriptNames;
	delete remoteAppManager;
}

FrontAppOperation FrontEnd::translateOperation(string opp){
		FrontOperationMap oppMap;
		oppMap["load"] = Load;
		oppMap["reload"] = Reload;
		oppMap["exit"] = ExitApp;

		return oppMap[opp];
}

void FrontEnd::start(string path){
	exit  = false;
	script = new ScriptManager(path);
	scriptNames = script->getNames();
	

	string text;
	cout << "Welcome to Project Management!" << endl;
	cout << "Available Applications: " << endl;
	while(!exit) {
		cout << endl;
		toLoad();
		//vector<string> args = readConsoleStrings();
		//string operation = args[0];

		//tests
		string operation = "load";

		switch (translateOperation(operation)){
		case Load:
			execLoad("Asana");//args[1]);
			break;
		case Reload:
			scriptNames = script->getNames();
		break;
		case ExitApp:
			exit = true;
			break;
		default:
			cout << endl << "incorrect command" << endl;
		}
		
	}
}

void FrontEnd::toLoad(){
	for(StringVector::iterator it = scriptNames->begin(); it!= scriptNames->end(); ++it){
			cout << *it << endl;
		}	
		cout << endl << "To load application type load <system name>" << endl << endl;
}

void FrontEnd::execLoad(string app){
	for(StringVector::iterator it = scriptNames->begin(); it!= scriptNames->end(); ++it){
				if(*it==app){
					cout << "loading " << app;
					remoteAppManager = new RemoteAppManager(app);
					remoteAppManager->start();
					return;
				}
	}
	cout << "incorrect system";
}

vector<string> FrontEnd::readConsoleStrings() {
	string text;
	char ch= ' ';
	cout << ">";
	getline(cin,text);
	string next;
    vector<string> result;
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
