#ifndef PYTHONADAPTER_H
#define PYTHONADAPTER_H
#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>
#include <vector>
#include "iostream"
#include "method.h"
#include "item.h"
#include "jsonreader.h"

typedef vector<Item*> ItemVector;
typedef vector<Method*> MethodVector;
typedef vector<string> StringVector;

using namespace std;
using namespace boost::python;

/**
 * @brief PythonAdapter
 *
 * Class raesponsible for executing methods in python
 *
 */

class PythonAdapter
{
private:

	/**
     * @brief appName
     *
     * Name script to use
	 *
     */
	string appName;

	/**
     * @brief jsonReader
	 *
     */
	JSONReader* jsonReader;
public:

	/**
     * @brief JSONReader
     * Constructor 
     * @param appName script to be used 
	 */
	PythonAdapter(string appName);

	/**
     * @brief JSONReader
     * Destructor
	 */
	~PythonAdapter(void);

	/**
     * @brief getItemPrototypes
     * Method reads item prototypes from script
     * @return vect vector<Item*>
	 */
	ItemVector* getItemPrototypes();

	/**
     * @brief getMethodPrototypes
     * Method reads method prototypes from script
     * @return vect vector<Method*>
	 */
	MethodVector* getMethodPrototypes();

	/**
     * @brief JSONReader
     * To - Do
     * @param params 
	 */
	void exec(StringVector params);
};

#endif