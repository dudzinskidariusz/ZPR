#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include <vector>
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Item*> ItemsMap;
typedef vector<string> StringVector;

/**
 * @brief ItemFactory
 *
 * Class is a prototype factory of items
 */
class ItemFactory
{
private:
	/**
     * @brief items
     *
     * Contains map of prototypes
	 *
     */
	ItemsMap* items;

public:

	/**
     * @brief ItemFactory
     * Constructor 
     * @param name 
	 */
	ItemFactory(void);

	/**
     * @brief ItemFactory
     * Destructor
	 */
	~ItemFactory(void);

	/**
     * @brief registerItem
     * Function registers a protorype and returns if opperation was a success
     * @param item
	 * @return result 
	 */
	bool registerItem(Item* item);

	/**
     * @brief crete
     * Creates a copy from prototype
     * @param name 
	 * @return item
	 */
	Item* create(string name);

	/**
     * @brief getNames
     * Returns vector<string> of names of items occuring in parameters map
	 * @return vect vector<string>
	 */
	StringVector* getNames();
};

#endif