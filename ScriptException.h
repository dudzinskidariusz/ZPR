#pragma once
#include "iostream"

using namespace std;
class ScriptException
{
private:
	string m_strError;
	//ScriptException(){};
public:
	ScriptException(string strError ="There is an error with a script, please check it and try again")
        : m_strError(strError)
    {
    }
	~ScriptException(void){};

	string GetError() { return m_strError; }
};
