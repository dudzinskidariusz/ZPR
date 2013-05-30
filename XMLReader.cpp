#include "XMLReader.h"
#include <boost/foreach.hpp>
#include "iostream"
#include "Method.h"
#include "Item.h"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include "json.h"
using namespace Json;

XMLReader::XMLReader(void)
{
}


XMLReader::~XMLReader(void)
{
}

Method readMethods( std::istream & is )
{
    // populate tree structure pt
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(is, pt);
	vector<Method*> methods;
    // traverse pt
    BOOST_FOREACH( ptree::value_type const& v, pt.get_child("methods") ) {
        if( v.first == "method" ) {
            Method* m = new Method();
            m->setName(v.second.get<std::string>("name"));
			Item* item = new Item(v.second.get<string>("param"));
            m->addParam("param",item);
			methods.push_back(m);
        }
    }
	lib_json.
		Json::Value root;
    return methods;
}