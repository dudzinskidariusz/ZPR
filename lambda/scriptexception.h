#ifndef SCRIPTEXCEPTION_H
#define SCRIPTEXCEPTION_H
#include "iostream"

using namespace std;

/**
 * @brief ScriptException 
 *
 * Exception created to stress problems with incorrectly structured python scripts
 *
 */
class ScriptException
{
private:
	/**
     * @brief m_strError
     *
     * contains the error text
	 *
     */
	string m_strError;

public:
	/**
     * @brief ScriptException
     * @param strError
     *
     * Constructor defining the error message, with deafult value
     *
     */
	ScriptException(string strError ="There is an error with a script, please check it and try again")
        : m_strError(strError)
    {
    }

	/**
     * @brief ScriptException
     *
     * simple destructor
     *
     * @return znak argumentu
     */
	~ScriptException(void){};

	/**
     * @brief getError
     *
     * returns the error message
     *
     * @return m_strError
     */
	string getError() { return m_strError; }
};

#endif