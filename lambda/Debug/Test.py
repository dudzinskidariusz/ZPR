'''
Created on 27-03-2013

@author: Darek
'''

methods = "[{"
methods +=  "\"method\":"
methods += "[\"getTests\", \"API_KEY\"]},{"
methods +=  "\"method\":"
methods += "[\"getTest\", \"id\", \"API_KEY\"]}]" 


items  = "[{"
items +=  "\"item\":"
items += "[\"authentication\",\"login\"]},{"
items +=  "\"item\":"
items += "[\"task\", \"task\", \"param\"]}]" 


''''users"
'''
#data = json.dumps({'name':'test', 'description':'some test repo'}) 


def getMethods	():
	methods = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>"
	methods += "<methods>"
	methods += "<method>"
	return methods
		

