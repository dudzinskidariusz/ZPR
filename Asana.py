'''
Created on 27-03-2013

@author: Darek
'''
import requests, json

API_KEY="1jUZqKkm.nz1jyrRsBWNkpxakpkfYinT"
asana_url = "https://app.asana.com/api/1.0/"


methods = "[{"
methods +=  "\"method\":"
methods += "[\"getUsers\", \"API_KEY\"]},{"
methods +=  "\"method\":"
methods += "[\"getUser\", \"id\", \"API_KEY\"]}]" 


items  = "[{"
items +=  "\"item\":"
items += "[\"authentication\", \"API_KEY\", \"login\"]},{"
items +=  "\"item\":"
items += "[\"projects\", \"param\"]},{"
items +=  "\"item\":"
items += "[\"task\", \"task\", \"param\"]}]" 


''''users"
'''
#data = json.dumps({'name':'test', 'description':'some test repo'}) 

class M:
	def __getitem__():
		methods =1;
		#methods = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>"
		#methods += "<methods>"
		#methods += "<method>"
		#methods += "<name>\"getUsers\"</name>"
		#methods += "<param>\"api_key\"</param>"
		#methods += "</method>"
		#methods += "</methods>"
		return methods
		

def getUsers(api_key):
    r = requests.get((asana_url+"users"), auth=(API_KEY, "" ))
    print (r.json)
#    print (r.text)

def getUser(id, api_key):
    r = requests.get((asana_url+"users/"+str(id)), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
        
def getUsersFromWorkspace(workspace, api_key):
    r = requests.get((asana_url+"workspaces/" +str(workspace)+"/users"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTask(task_id, api_key):
    r = requests.get((asana_url+"tasks/" + str(task_id)), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTasksForUser(api_key):
    r = requests.get((asana_url+"tasks/"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTasksPerProject(project_id, api_key):
    r = requests.get((asana_url+"projects/" + str(project_id) + "/tasks"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTasksPerWorkspace(workspace_id, api_key):
    r = requests.get((asana_url+"workspaces/" +str(workspace_id) + "/tasks"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)

'''do prezentacji
def getSubtasks():
    r = requests.get((asana_url+"users"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
    '''
def getStories(task_id, api_key):
    r = requests.get((asana_url+"tasks/"+str(task_id) + "/stories"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getProjectPerTask(task_id, api_key):
    r = requests.get((asana_url+"tasks/" + str(task_id) + "/projects"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTagsPerTask(task_id, api_key):
    r = requests.get((asana_url+"tasks/"+str(task_id) + "/tags"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getProject(projects_id, api_key):
    r = requests.get((asana_url+"projects/"+str(projects_id)), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getProjects( api_key):
    r = requests.get((asana_url+"projects"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getProjectsFromWorkspace(worjspace_id, api_key):
    r = requests.get((asana_url+"workspaces/"+ str(worjspace_id) + "/projects"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTag(Tag_id, api_key):
    r = requests.get((asana_url+"tags/"+str(Tag_id)), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTasksWithTag(tag_id, api_key):
    r = requests.get((asana_url+"tags/"+str(tag_id) + "/tasks"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTags(tags, api_key):
    r = requests.get((asana_url+"tags"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getTagsFromWorkspace(workspace_id, api_key):
    print(asana_url+"workspaces/"+ str(workspace_id) + "/tags")
    r = requests.get((asana_url+"workspaces/"+ str(workspace_id) + "/tags"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getStoriesFromProject(project_id, api_key):
    r = requests.get((asana_url+"projects/"+str(project_id) + "/stories"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getStory(story_id, api_key):
    r = requests.get((asana_url+"stories/"+str(story_id)), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def getWorkspaces( api_key):
    r = requests.get((asana_url+"workspaces"), auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)
    
def postProject(name, workspace, notes,  api_key):
    payload = {'name':name},{'workspace':str(workspace)},{'notes':notes}
    data=json.dumps(payload)
    r = requests.post((asana_url+"workspaces/" + str(workspace) + "/projects"), data, auth=(API_KEY, "" ))
    print (r.json)
    print (r.text)


#test_workspace = 4653032378172

#postProject('test posta', test_workspace, 'test','')



