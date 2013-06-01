#ifndef JSONREADER_H
#define JSONREADER_H
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "item.h"
#include "json.h"
#include "scriptexception.h"

using namespace Json;

typedef vector<Item*> ItemVector;

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
	 * @param type
	 * @return vect vector<Item*> 
	 */
	ItemVector* readItems(string itemString, string type);
	
};

#endif