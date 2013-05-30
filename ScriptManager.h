#pragma once
#include "iostream"
#include <boost/filesystem.hpp>

namespace fs = ::boost::filesystem;
using namespace std;

typedef vector<string> StringVector;

class ScriptManager
{
private:
	StringVector* vect;
	StringVector* get_all(const fs::path& root);
public:
	ScriptManager(string fullPath);
	~ScriptManager(void);

	StringVector* getNames();
	
};

