#ifndef METHODFACTORY_H
#define METHODFACTORY_H
#include "method.h"
#include "iostream"
#include <vector>
#include <boost\unordered_map.hpp>

using namespace std;

typedef boost::unordered_map<string, Method*> MethodsMap;
typedef vector<string> StringVector;

/**
 * @brief MethodFactory
 *
 * Class is a prototype factory of methods 
 *
 */
class MethodFactory{
private:

	/**
     * @brief methods
     *
     * Contains map of prototypes
	 *
     */
	MethodsMap* methods;
public:

	/**
     * @brief MethodFactory
     * Constructor 
     * @param name 
	 */
	MethodFactory(void);

	/**
     * @brief MethodFactory
     * Destructor
	 */
	~MethodFactory(void);

	/**
     * @brief registerMethod
     * Function registers a protorype and returns if opperation was a success
     * @param method
	 * @return result 
	 */
	bool registerMethod(Method* method);

	/**
     * @brief crete
     * Creates a copy from prototype
     * @param name 
	 * @return method
	 */
	Method* create(string name);

	/**
     * @brief getNames
     * Returns vector<string> of names of methods occuring in parameters map
	 * @return vect vector<string>
	 */
	StringVector* getNames();

};

#endif