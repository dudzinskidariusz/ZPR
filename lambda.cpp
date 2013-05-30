#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>

#include <boost/foreach.hpp>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include "JSONReader.h"
#include "ScriptManager.h"
#include "FrontEnd.h"

using namespace std;
using namespace boost::python;

typedef vector<string> StringVector;
typedef boost::unordered_map<string, AppOperation> OperationMap;



int main(int argc,char** argv) {
	
	FrontEnd frontEnd;
	frontEnd.start(argv[0]);

	cout << endl;// <<"m "<< m.getName();
	char c;
	cin >> c;
	return 1;
}

