#include "jsonreader.h"
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "item.h"
//#include "json.h"

using namespace Json;

typedef vector<Item*> ItemVector;

JSONReader::JSONReader(void)
{
}


JSONReader::~JSONReader(void)
{
}


ItemVector* JSONReader::readItems(string itemString, string type){
	
		ItemVector* vect = new ItemVector();
		Value root;   
		Reader reader;
		bool parsingSuccessful = reader.parse( itemString, root );
		if ( !parsingSuccessful )
		{
			throw ScriptException();
		}
		for ( int i = 0; i < (int)root.size(); i++ ){ 
			Item* item = readItem(root[i][type]);
			vect->push_back(item);
		}
		return vect;		
}

Item* JSONReader::readItem(Value value){

		string name = value[0].asString();
		Item* item = new Item(name);
		for ( int j = 1; j < (int)value.size(); j++ ){
				name = value[j].asString();
				item->addParam(name);
			
			}
		return item;
	
}
