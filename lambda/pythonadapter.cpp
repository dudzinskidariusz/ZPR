#include "pythonadapter.h"


PythonAdapter::PythonAdapter(string appName)
{
	this->appName=appName;
	jsonReader = new JSONReader();
}


PythonAdapter::~PythonAdapter(void)
{
	delete jsonReader;
}

ItemVector* PythonAdapter::getItemPrototypes(string type){
	
	const char* cType = type.c_str();
	Py_Initialize();

	boost::python::str name (appName);
	//string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
	object app = import(name);
	
	object items = app.attr(cType);
	string str = extract<string>(items);
	Py_Finalize();

	JSONReader reader;
	return reader.readItems(str,type.substr(0,type.size()-1));
}

void PythonAdapter::exec(Item* method){
	Py_Initialize();
	try{
		//string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
		const char* name = appName.c_str();
		string ss =method->getName();
		const char* methodName = ss.c_str();
		
		object app = import(name);
		object ob = app.attr(methodName); // name (appName);
		
		object res;
		StringVector* names = method->getNames();
		
		StringVector::iterator it = names->begin();


		if(method->getParams()->size()==0){
			res =ob();
		}else if(method->getParams()->size()==1){
			res =ob(method->getParam(*it));
		}else if(method->getParams()->size()==2){
			res =ob(method->getParam(*it),
						method->getParam(*(++it)));
		}else if(method->getParams()->size()==3){
			res =ob(method->getParam(*it), 
						method->getParam(*(++it)),
						method->getParam(*(++it)));
		}else if(method->getParams()->size()==4){
			res =ob(method->getParam(*it), 
						method->getParam(*(++it)),
						method->getParam(*(++it)),
						method->getParam(*(++it)));
		}else if(method->getParams()->size()==5){
			res =ob(method->getParam(*it), 
						method->getParam(*(++it)),
						method->getParam(*(++it)),
						method->getParam(*(++it)),
						method->getParam(*(++it)));
		}

		string str = extract<string>(res);
		cout << endl << "C++:" << endl <<str;
	}catch(const error_already_set& e){
		cout << "error during executing python script";
	}
	Py_Finalize();
}