#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include "iostream"
#include "Method.h"
#include "Item.h"
using namespace std;
using namespace boost::python;

Method read( std::istream & is )
{
    // populate tree structure pt
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(is, pt);
 
    // traverse pt
    Method f;
    BOOST_FOREACH( ptree::value_type const& v, pt.get_child("sked") ) {
        if( v.first == "flight" ) {
            //Method f;
            f.setName(v.second.get<std::string>("name"));
			Item* item = new Item(v.second.get<string>("param"));
			
            f.addParam("param",item);
        }
    }
 
    return f;
}



int main(int, char **) {
 Py_Initialize();
	string API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT";
	string method = "Asana.getUsers(" ;
	method += API_KEY;
	method +=  ")";
	try {
	//object main_module = import("__main__");
	//object main_namespace = main_module.attr("__dict__");
	//boost::python::exec("import Asana");
	PyRun_SimpleString("import Asana");
	//object rand = 
	//	eval("Asana.getMethods()");
	//std::cout << 
		string str = "";//extract<string>(rand);
		cout << str;
	//PyRun_SimpleString("import Asana");
	object result = exec("Asana.getMethods()");
	//PyRun_SimpleString("Asana.getMethods()");
	//string res = extract<string>(result);
  Py_Finalize();
  //std::istringstream iss(str);
  //Method m = read(iss);
  } catch (const error_already_set& e) {
	cout << "error";
}
  cout << "m ";// << m.getName();
  char c;
  cin >> c;
  return 1;
}

