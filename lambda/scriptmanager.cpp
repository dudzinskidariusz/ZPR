#include "scriptmanager.h"
#include <boost/filesystem.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

namespace fs = ::boost::filesystem;


ScriptManager::ScriptManager(string fullPath)
{
	path=fullPath;
	int pos = path.find("pmapp.exe");
	path = path.substr(0, pos);
	vect = getAll(path);
}


ScriptManager::~ScriptManager(void)
{
	delete vect;
}

StringVector* ScriptManager::getNames(){
	int pos = path.find("pmapp.exe");
	path = path.substr(0, pos);
	vect = getAll(path);
	return vect;
}

StringVector* ScriptManager::getAll(const fs::path& root)
{  
	if (!fs::exists(root)) {
		return 0;
	}
	StringVector* vect = new StringVector();
	if (fs::is_directory(root)){
		fs::recursive_directory_iterator it(root);
		fs::recursive_directory_iterator endit;
		string file;
		while(it != endit)
		{
			file = it->path().filename().string();
			int pos = file.find('.');
			string ext = file.substr(pos+1);
			if(ext == "py"){
				vect->push_back(file.substr(0, pos));
			}
			++it;
		}
	  }
	  return vect;
}