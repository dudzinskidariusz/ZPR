#include "ScriptManager.h"
#include <boost/filesystem.hpp>
#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

namespace fs = ::boost::filesystem;


ScriptManager::ScriptManager(string fullPath)
{
	int pos = fullPath.find("lambda.exe");
	fullPath = fullPath.substr(0, pos);
	vect = get_all(fullPath);
}


ScriptManager::~ScriptManager(void)
{
	delete vect;
}

StringVector* ScriptManager::getNames(){
	return vect;
}

StringVector* ScriptManager::get_all(const fs::path& root)
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