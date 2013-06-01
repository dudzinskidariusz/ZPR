#ifndef FRONTAEND_H
#define FRONTAEND_H
#include <boost/foreach.hpp>
#include "iostream"
#include "item.h"
#include "jsonreader.h"
#include "scriptmanager.h"
#include "remoteappmanager.h"


using namespace std;

/**
 * @brief FrontAppOperation
 *
 * Enum expresses operation to perform 
 */
static enum FrontAppOperation { 
	Load, 
	Reload,
	ExitApp };

typedef vector<string> StringVector;
typedef boost::unordered_map<string, FrontAppOperation> FrontOperationMap;

/**
 * @brief FrontEnd
 *
 * Class responsible for displaying proper content in the command line
 *
 */
class FrontEnd
{
private:

	/**
     * @brief translateOperation
     * translates string to enum
     * @param opp string with operation name
	 * @return frontAppOperation enum 
     */
	FrontAppOperation translateOperation(string opp);

	/**
     * @brief toLoad
     * displays available systems, application can connect to based on available scripts
     */
	void toLoad();

	/**
     * @brief readConsoleStrings
     * reads a line, splits is by a ' ' sign and returns as vector of strings
     * @return result vector of strings
    */
	vector<string> readConsoleStrings();

	/**
     * @brief execLoad
     * Starts work on script
     * @param app script name
     */
    void execLoad(string app);
	
	/**
     * @brief exit
     *
     * used in while loop to sustain work of the front end
	 *
     */
	bool exit;

	/**
     * @brief script
     *
     * Script Manager to retrieve script names from folder
	 *
     */
	ScriptManager* script;

	/**
     * @brief scriptNames
     *
     * contains names of python scripts in the aplication folder
	 *
     */
	StringVector* scriptNames;

	/**
     * @brief remoteAppManager
     */
	RemoteAppManager* remoteAppManager;

public:

	/**
     * @brief FrontEnd
     * Simple constructor
       */
	FrontEnd(void);

	/**
     * @brief FrontEnd
     * Simple destructor
     */
	~FrontEnd(void);

	/**
     * @brief start
     * Starts the work of the front end
	 * Responsible for loading script names and rechecking aplicaiton folder
     * @param path
     */
	void start(string path);
};

#endif