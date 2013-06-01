#ifndef REMOTEAPPMANAGER_H
#define REMOTEAPPMANAGER_H
#include "itemfactory.h"
#include "pythonadapter.h"
#include "jsonreader.h"
#include "scriptexception.h"

/**
 * @brief AppOperation
 *
 * Enum expresses operation to perform 
 */
static enum AppOperation {
	Wrong,
	Execute, 
	Exit };

typedef vector<string> StringVector;
typedef boost::unordered_map<string, AppOperation> OperationMap;
typedef boost::unordered_map<string, string> ItemMap;

/**
 * @brief RemoteAppManager
 *
 * An interface between user and remote application through python scripts
 *
 */
class RemoteAppManager
{
private:

	/**
     * @brief initFactories
     * Private function to init Item and Method factories
	 */
	void initFactories();

	/**
     * @brief readConsoleStrings
     * Reads single line from console, splits the string and return it as vector<string>
     * @return vect vector<string> 
	 */
	vector<string> readConsoleStrings();
	
	/**
     * @brief printMethods
     * Prints available methods to the console
     */
	void printMethods();
	
	/**
     * @brief translateOperation
     * translates string to enum
     * @param opp string with operation name
	 * @return appOperation enum 
     */
	AppOperation translateOperation(string opp);
	
	/**
     * @brief exec
     * To - Do
     */
	void exec();
	
	/**
     * @brief createItem
     * Creates Item and fills and prompts user to fill data
	 * @param type type of item method or item
	 * @param name name of object to create
	 * @return item
     */
	Item* createItem(string type, string name);
	

	/**
     * @brief authReq
	 * item contains user's authentication credentials
     */
	Item* auth;

	/**
     * @brief appName
     */
	string appName;

	/**
     * @brief exit
	 * used in while loop to sustain work of the remote app manager
     */
	bool exit;

protected:

	/**
     * @brief itemFactory
     */
	ItemFactory* itemFactory;

	/**
     * @brief methodFactory
     */
	ItemFactory* methodFactory;

	/**
     * @brief pythonAdapter
     */
	PythonAdapter* pythonAdapter;

public:
	/**
     * @brief JSONReader
     * Constructor, initiates factories and python adapter
     * @param appName script to be used 
	 */
	RemoteAppManager(string appName);

	/**
     * @brief JSONReader
     * Destructor
     * @param appName script to be used 
	 */
	~RemoteAppManager(void);

	/**
     * @brief start
     * Communication between user and remote application
     */
	void start();
};

#endif
