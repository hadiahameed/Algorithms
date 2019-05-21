const mongoCollections = require("./mongoCollections");
const todoItems = mongoCollections.todoItems;
const uuid = require('uuid/v1');

module.exports = {
    async getTask(id){
    if(!id) throw "You must provide an id to search for."
    if (typeof(id)!='string') throw "Id must be a string.";
    const todoItemCollection = await todoItems();
     
    const selected_task = await todoItemCollection.findOne({_id: id});
    if(selected_task == null) throw `No task with that id exists.`

    return selected_task;         

    },

    async createTask(title,description) {
        if (!title) throw `You must provide title of the task.`
        if (typeof(title)!='string') throw "Title must be a string.";
        if (!description) throw `You must provide desription for the task.`
        if (typeof(description)!='string') throw "Description Must be a string.";
        const todoItemCollection = await todoItems();
        
        let uuid1 = uuid();
        let newTask = {
            _id: uuid1, 
            title: title, 
            description: description, 
            completed: false, 
            completedAt: null};
         
        const insertInfo = await todoItemCollection.insertOne(newTask);
        
        if(insertInfo.insertedCount == 0) throw "Could not add task.";
        const newId = insertInfo.insertedId; 
        
        const task = await this.getTask(newId);
        return task; 
    },

    async getAllTasks(){      
        const todoItemCollection = await todoItems();
        const tasks = await todoItemCollection.find({}).toArray();
        return tasks;
        
    },

    async completeTask(taskId){
        if (!taskId) throw "You must provide an id to search for";
        if (typeof(taskId)!='string') throw "Id must be a string.";
        const todoItemCollection = await todoItems();
        //https://stackoverflow.com/questions/18229022/how-to-show-current-time-in-javascript-in-the-format-hhmmss
        var today = new Date();
        var h = today.getHours();
        var m = today.getMinutes();
        if(h>=12) var t = "pm";
        else var t = "am";
        let task = await this.getTask(taskId);
        let updatedTask = {
            title: task.title,
            description: task.description,
            completed: true,
            completedAt: h+" : "+m+t
        }

        const updatedInfo = await todoItemCollection.update({ _id: taskId }, updatedTask);
        if (updatedInfo.modifiedCount === 0) {
            throw "Could not update task successfully";
        }
        return await this.getTask(taskId);
    },

    async removeTask(id){
        if (!id) throw "You must provide an id to search for.";
        if (typeof(id)!='string') throw "Id must be a string.";
        const todoItemCollection = await todoItems();
        const deletionInfo = await todoItemCollection.removeOne({ _id: id });
        if (deletionInfo.deletedCount === 0) {
            throw `Could not delete task with id of ${id}`;
        }
        return true;
    }
        

}
