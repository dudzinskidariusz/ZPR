#include "AgileManager.h"


AgileManager::AgileManager(void)
{
	itemFactory = new ItemFactory();
	methodFactory = new MethodFactory();
	pythonAdapter = new PythonAdapter();
	jsonReader = new JSONReader();

}


AgileManager::~AgileManager(void)
{
	delete itemFactory ;
	delete methodFactory;
	delete pythonAdapter;
	delete jsonReader;
}
