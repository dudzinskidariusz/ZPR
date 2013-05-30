#pragma once
#include "iostream"
#include <boost/filesystem.hpp>

namespace fs = ::boost::filesystem;
using namespace std;

class ScriptManager
{
public:
	ScriptManager(void);
	~ScriptManager(void);

	string getNames(string path);
	void get_all(const fs::path& root,const string& ext);
};

