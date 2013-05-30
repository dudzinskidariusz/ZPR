#include "JSONReader.h"
#include <boost/foreach.hpp>
#include <vector>
#include "iostream"
#include "Method.h"
#include "Item.h"
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
		std::cout  << "Failed to parse configuration\n"
				   << reader.getFormattedErrorMessages();
		return vect;
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

string JSONReader::writeItems(ItemVector* vector){

	Value root; 
	root["indent"]["length"] = 1;
root["indent"]["use_space"] = 12;

StyledWriter writer;
// Make a new JSON document for the configuration. Preserve original comments.
std::string outputConfig = writer.write( root );

// You can also use streams.  This will put the contents of any JSON
// stream at a particular sub-value, if you'd like.

// And you can write to a stream, using the StyledWriter automatically.
std::cout << root;

return "";

}


MethodVector* JSONReader::readMethods(string methodString){
	
	MethodVector* vect = new MethodVector();
	
	Value root;   
	Reader reader;
	bool parsingSuccessful = reader.parse( methodString, root );
	if ( !parsingSuccessful )
	{
		std::cout  << "Failed to parse configuration\n"
				   << reader.getFormattedErrorMessages();
		return vect;
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