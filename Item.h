#ifndef ITEM_H
#define ITEM_H
#include <boost\unordered_map.hpp>
//prototype
using namespace std;

/**
 * @brief Item
 *
 * Class is a prototype, represents an item available from the remote application
 * contains it's name and atributes
 *
 */
class Item
{
	typedef boost::unordered_map<string, string> ItemMap;

private:

	/**
     * @brief name
     *
     * Name of item
	 *
     */
	string name;

	/**
     * @brief params
     *
     * Map of parameters
	 *
     */
	ItemMap params;
public:

	/**
     * @brief Item
     * Constructor setting the name of item
     * @param name 
	 */
	Item(string name);

	/**
     * @brief Item
     * Copying constructor
     */
	Item(const Item& i);

	/**
     * @brief clone
     * Clones an item
     * @return item
     */
	Item* clone() const;

	/**
     * @brief Item
     * Simple destructor
     */
	~Item(void);

	/**
     * @brief setName
     * Sets item name
     * @param name
	 */
	void setName(string name);

	/**
     * @brief getName
     * Gets Name
	 * @return name 
     */
	string getName();

	/**
     * @brief addParam
     * Adds a new parameter to the map
     * @param key parameter name
	 * @param value parameter value
	 */
	void addParam(string key, string value="");

	/**
     * @brief getParam
     * Returns parameter value
     * @param key parameter name
	 * @return value
     */
	string getParam(string key);

	/**
     * @brief getParams
     * Returns parameters map
     * @return params
     */
	ItemMap* getParams();

	
};
#endif
