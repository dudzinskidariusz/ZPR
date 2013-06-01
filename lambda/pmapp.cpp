#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>

#include <boost/foreach.hpp>
#include "iostream"
#include "item.h"
#include "jsonreader.h"
#include "scriptmanager.h"
#include "frontend.h"

using namespace std;
using namespace boost::python;

typedef vector<string> StringVector;
typedef boost::unordered_map<string, AppOperation> OperationMap;



int main(int argc,char** argv) {
	
	FrontEnd frontEnd;
	frontEnd.start(argv[0]);
	cout << endl;
	char c;
	cin >> c;
	return 1;
}

