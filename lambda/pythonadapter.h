#ifndef PYTHONADAPTER_H
#define PYTHONADAPTER_H
#include <boost/python/detail/wrap_python.hpp>// musi byæ pierwsze
#include <boost/python.hpp>
#include <vector>
#include "iostream"
#include "item.h"
#include "jsonreader.h"

typedef vector<Item*> ItemVector;
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
	ItemVector* getItemPrototypes(string type);

	/**
     * @brief JSONReader
     * Executes method on script
     * @param method 
	 */
	void exec(Item* method);
};

#endif