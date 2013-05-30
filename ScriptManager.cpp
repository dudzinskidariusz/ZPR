#include "ScriptManager.h"
#include <boost/filesystem.hpp>

namespace fs = ::boost::filesystem;

ScriptManager::ScriptManager(void)
{
}


ScriptManager::~ScriptManager(void)
{
}

string ScriptManager::getNames(string path){
	get_all(path, "py");
	return "";
}


// return the filenames of all files that have the specified extension
// in the specified directory and all subdirectories
void ScriptManager::get_all(const fs::path& root, const string& ext)
{  
  if (!fs::exists(root)) return;

  if (fs::is_directory(root))
  {
    fs::recursive_directory_iterator it(root);
    fs::recursive_directory_iterator endit;
    while(it != endit)
    {
		//if (fs::is_regular_file(*it) && it->extension() == ext)
     cout <<it->path();
      ++it;
    }
  }
}