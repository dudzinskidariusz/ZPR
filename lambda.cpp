#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>

#include <boost/foreach.hpp>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include "JSONReader.h"
#include "ScriptManager.h"
using namespace std;
using namespace boost::python;





int main(int argc,char** argv) {
	string path = argv[0];
	int pos = path.find("lambda.exe");
	path = path.substr(0, pos);
	cout <<  path<< endl;
	ScriptManager script;
	script.getNames(argv[0]);

 Py_Initialize();
	string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
	object asana = import("Asana");
		object methods = asana.attr("methods");
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
		string str = extract<string>(methods);
		cout << str << endl << endl;
	//PyRun_SimpleString("import Asana");
	//
	
		//object result = exec("Asana.getMethods()");
	//PyRun_SimpleString("Asana.getMethods()");
	//string res = extract<string>(result);
  Py_Finalize();

  JSONReader* reader = new JSONReader();
  reader->readItems(str);

  cout << endl;// <<"m "<< m.getName();
  char c;
  cin >> c;
  return 1;
}

