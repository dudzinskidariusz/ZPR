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

ItemVector* PythonAdapter::getItemPrototypes(){

	Py_Initialize();

	boost::python::str name (appName);
	//string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
	object app = import(name);
	object items = app.attr("items");
	string str = extract<string>(items);
	Py_Finalize();

	JSONReader* reader = new JSONReader();
	return reader->readItems(str);
}

MethodVector* PythonAdapter::getMethodPrototypes(){

	Py_Initialize();

	boost::python::str name (appName);
	//string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
	object app = import(name);
	object items = app.attr("methods");
	string str = extract<string>(items);
	
	Py_Finalize();

	JSONReader* reader = new JSONReader();
	return reader->readMethods(str);
}

void PythonAdapter::exec(StringVector params){
	// TO-DO
	/*
		try
	{
		//object a = exec_file("Asana.py",asana, asana);
		//object r= a["getMethods"];
		
		//std::string message = extract<std::string>(r());
		//std::cout << message << std::endl;
		//object m = exec("Asana.M()", asana);
	}catch 	(error_already_set const &)
	{
    if (PyErr_ExceptionMatches(PyExc_ZeroDivisionError))
    {
        // handle ZeroDivisionError specially
    }
    else
    {
        // print all other errors to stderr
        PyErr_Print();
		char c1;
		cin >> c1;
    }
}
*/
	//object main_namespace = main_module.attr("__dict__");
	//boost::python::exec("import Asana");
	//PyRun_SimpleString("import Asana");
	////std::cout << 
	//	string str = extract<string>(items);
//cout << str << endl << endl;
	//PyRun_SimpleString("import Asana");
	//
	
		//object result = exec("Asana.getMethods()");
	//PyRun_SimpleString("Asana.getMethods()");
	//string res = extract<string>(result);
}