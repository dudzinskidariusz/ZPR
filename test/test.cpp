#pragma once
#include "StdAfx.h"
#include "pmapptest.h"
#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>


/**
*	Test checks initation internal structures from the script
*	Includes:
*	Parsing from JSON to method & item
*	Prototype factories initiation
*/
BOOST_AUTO_TEST_CASE( readScriptTest )
{
    PMappTest* testObject = new PMappTest();
	StringVector* methods = testObject->getMethodFactory()->getNames();
	
	Item m1("getUsers");
	m1.addParam("API_KEY");
	Item m2("getUser");
	m2.addParam("id");
	m2.addParam("API_KEY");

	Item* tm1 = testObject->getMethodFactory()->create("getUsers");
	BOOST_CHECK(m1.getParam("API_KEY") == tm1->getParam("API_KEY"));

	Item* tm2 = testObject->getMethodFactory()->create("getUser");
	BOOST_CHECK(m2.getParam("id") == tm2->getParam("API_KEY"));
	BOOST_CHECK(m2.getParam("API_KEY") == tm2->getParam("API_KEY"));
	
	StringVector* items = testObject->getItemFactory()->getNames();
	
	Item i1("authentication");
	i1.addParam("API_KEY");
	i1.addParam("login");
	Item i2("task");
	i1.addParam("param");
	
	Item* ti1 = testObject->getItemFactory()->create("authentication");
	BOOST_CHECK(i1.getParam("API_KEY") == ti1->getParam("API_KEY"));
	BOOST_CHECK(i1.getParam("login") == ti1->getParam("login"));

	Item* ti2 = testObject->getItemFactory()->create("task");
	BOOST_CHECK(i2.getParam("param") == ti2->getParam("param"));
	
	cout << endl << "readScriptTest completed" << endl;
	char c;
	cin >> c;
	
}

//EOF