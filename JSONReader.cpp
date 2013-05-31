#include "jsonreader.h"
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "method.h"
#include "item.h"
//#include "json.h"

using namespace Json;

typedef vector<Item*> ItemVector;
typedef vector<Method*> MethodVector;

JSONReader::JSONReader(void)
{
}


JSONReader::~JSONReader(void)
{
}


ItemVector* JSONReader::readItems(string itemString){
	
		ItemVector* vect = new ItemVector();
		Value root;   
		Reader reader;
		bool parsingSuccessful = reader.parse( itemString, root );
		if ( !parsingSuccessful )
		{
			throw ScriptException();
		}
		//cout << "root : "  << root <<endl;
		for ( int i = 0; i < (int)root.size(); i++ ){ 
			Item* item = readItem(root[i]["item"]);
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
		//std::cout << "item readed "<< item->getName() << " : "<< item->getParamNames() << endl; 
		return item;
	
}

MethodVector* JSONReader::readMethods(string methodString){
		MethodVector* vect = new MethodVector();
	
		Value root;   
		Reader reader;
		bool parsingSuccessful = reader.parse( methodString, root );
		if ( !parsingSuccessful )
		{
			throw ScriptException();
		}
		//cout << "root : "  << root <<endl;
		for ( int i = 0; i < (int)root.size(); i++ ){ 
			Method* method = readMethod(root[i]["method"]);
			vect->push_back(method);
		}
		return vect;
}

Method* JSONReader::readMethod(Value value){

		string name = value[0].asString();
		Method* method = new Method(name);
		for ( int j = 1; j < (int)value.size(); j++ ){
				name = value[j].asString();
				method->addParam(name);
		}
		//std::cout << "method readed from file"<< method->getName() << " : "<< method->getParamNames() << endl; 
		
		return method;
}