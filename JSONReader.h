#ifndef JSONREADER_H
#define JSONREADER_H
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "method.h"
#include "item.h"
#include "json.h"
#include "scriptexception.h"

using namespace Json;

typedef vector<Item*> ItemVector;
typedef vector<Method*> MethodVector;

/**
 * @brief JSONReader
 *
 * Class reads objects from strings and transforms them to final form
 *
 */
class JSONReader
{
private:

	/**
     * @brief readItem
     * Private function used to read single item
     * @param Value - Json::Value
	 * @return item 
	 */
	Item* readItem(Value value);

	/**
     * @brief readMethod
     * Private function used to read single method
     * @param Value Json::Value
	 * @return method
	 */
	Method* readMethod(Value value);
public:

	/**
     * @brief JSONReader
     * Constructor 
     */
	JSONReader(void);

	/**
     * @brief JSONReader
     * Destructor
     */
	~JSONReader(void);

	/**
     * @brief readItems
     * Function parses string to vector<Item*>
     * @param itemString
	 * @return vect vector<Item*> 
	 */
	ItemVector* readItems(string itemString);
	
	/**
     * @brief readMethods
     * Function parses string to vector<Method*>
     * @param itemString
	 * @return vect vector<Method*> 
	 */
	MethodVector* readMethods(string itemString);
	
};

#endif