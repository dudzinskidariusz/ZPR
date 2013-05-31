#ifndef METHOD_H
#define METHOD_H
#include <boost\unordered_map.hpp>
#include "item.h"
//prototype
using namespace std;

/**
 * @brief Method
 *
 * Class is a prototype, represents a method available to perform on remote application
 * contains it's name and atributes (in form of items)
 *
 */
class Method
{
	typedef boost::unordered_map<string, Item*> MethodMap;
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
	MethodMap params;
public:

	/**
     * @brief Method
     * Constructor setting the name of item
     * @param name 
	 */
	Method(string name);

	/**
     * @brief Method
     * Copying construcor
     */
	Method(const Method& i);

	/**
     * @brief Method
     * Clones a method
	 */
	Method* clone() const;

	/**
     * @brief Method
     * Destructor
    */
	~Method(void);


	/**
     * @brief setName
	 * Sets name
     * @param name 
	 */
	void setName(string name);

	/**
     * @brief getParam
     * Returns name
	 * @param name
	 */
	string getName();

	/**
     * @brief addParam
     * Adds a new parameter to the map
     * @param key parameter name
	 * @param value parameter value
	 */
	void addParam(string key, Item* value = 0);

	/**
     * @brief getParam
     * Returns a param with specific name
     * @param key parameter name
	 * @return param
	 */
	Item* getParam(string key);

	/**
     * @brief getParams
     * Returns parameters map
     * @return params
	 */
	MethodMap* getParams();

};

#endif