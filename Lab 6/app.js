const express = require('express');
const app = express();
const configRoutes = require('./routes');

configRoutes(app);

app.listen(3000,function(){
    console.log("Server started: Port = 3000");
    console.log("url: http://localhost:3000"); 
})