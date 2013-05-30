#pragma once
#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>
#include <vector>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include "JSONReader.h"

typedef vector<Item*> ItemVector;
typedef vector<Method*> MethodVector;
typedef vector<string> StringVector;

using namespace std;
using namespace boost::python;

class PythonAdapter
{
private:
	string appName;
	JSONReader* jsonReader;
public:
	PythonAdapter(string appName);
	~PythonAdapter(void);

	ItemVector* getItemPrototypes();
	MethodVector* getMethodPrototypes();
	void exec(StringVector params);
};

