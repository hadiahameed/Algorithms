const todoItems = require("./todo");
const connection = require("./mongoConnection");

const main = async() =>{
  let createdTask1 = {};
  let createdTask2 = {};
  try{
    console.log("");
    console.log("--------Creating Task 1--------");
    createdTask1 = await todoItems.createTask("Ponder Dinosaurs", "Has Anyone Really Been Far Even as Decided to Use Even Go Want to do Look More Like?");
    console.log(createdTask1);
  }
  catch(e){
    throw e;
  }

  try{
    console.log("");
    console.log("--------Creating Task 2--------");
    createdTask2 = await todoItems.createTask("Play Pokemon with Twitch TV", "Should we revive Helix?");
    console.log(createdTask2);
  }
  catch(e){
    throw e;
  }

  try{
    console.log("");
    console.log("--------Querying all tasks and logging them--------");
    let allTasks = await todoItems.getAllTasks();
    console.log(allTasks);
  }
  catch(e){
    throw e;
  }

  try{
    console.log("");
    console.log("--------Removing First Task--------");
    await todoItems.removeTask(createdTask1._id);
  }
  catch(e){
    throw e;
  }

  try{
    console.log("");
    console.log("--------Querying remaining tasks and logging them--------");
    allTasks = await todoItems.getAllTasks();
    console.log(allTasks);
  } 
  catch(e){
    throw e;
  }

  console.log(" ");
  console.log("--------Completing remaining tasks and logging them--------");
  for (i=0;i<(allTasks.length%4);i++){
    try{
      console.log(" ")
      console.log("Task "+(i+1)+" : ")
      const completedTask = await todoItems.completeTask(allTasks[i]._id);
      console.log(completedTask);
    }
    catch(e){
      throw e;
    }
}
  const db = await connection();
  await db.serverConfig.close();
  console.log("Done!");

 
  
  
}

main().catch(error => {
  console.log(error)
});