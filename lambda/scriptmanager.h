#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H
#include "iostream"
#include <boost/filesystem.hpp>

namespace fs = ::boost::filesystem;
using namespace std;

typedef vector<string> StringVector;

/**
 * @brief ScriptManager
 *
 * Reads scripts in directory
 *
 */
class ScriptManager
{
private:
	
	/**
     * @brief path
	 */
	string path;

	/**
     * @brief vect
     * Script vector
	 */
	StringVector* vect;

	/**
     * @brief getAll
     * Returns string vector of scripts available
     * @param root
	 * @return vect vector<string>
	 */
	StringVector* getAll(const fs::path& root);

public:

	/**
     * @brief ScriptManager
     * Constructor 
     * @param fullPath 
	 */
	ScriptManager(string fullPath);

	/**
     * @brief ScriptManager
     * Destructor
	 */
	~ScriptManager(void);

	/**
     * @brief getNames
     * 
     * @return vect vector<string>
	 */
	StringVector* getNames();
	
};

#endif