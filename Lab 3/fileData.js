const bluebird = require("bluebird");
const fs = bluebird.promisifyAll(require("fs"));

async function getFileAsString(path){
    try{
        const StringFile = await fs.readFileAsync(path, "utf-8");
        return StringFile;
    }
    
    catch(e){
        throw  `Error reading file: ${e}`
    }

}
    
async function getFileAsJSON(path){

    try{
        const JSONString = await fs.readFileAsync(path, "utf-8");
        try{
            var JSONobj = JSON.parse(JSONString)
        }
        catch(e){
            throw `INVALID JSON: ${e}`
        }
    }
    catch(e){
        return false;
    }
    return JSONobj;
}

async function saveStringToFile(path, text){
    try{
        await fs.writeFileAsync(path, text);
        return true;
    }
    catch(e){
        throw `Error saving file: ${e}`;
    }
    
}

async function saveJSONToFile(path, obj){
    
    try {
        const JSONString = JSON.stringify(obj);
        try {
            await fs.writeFileAsync(path, JSONString);
            return true;
        }
        catch(e){
            throw `Error saving file: ${e}`;
        }
    }
    catch(e){
        throw `Invalid JSON object`;
    }       
        
    
}


module.exports = {
    firstName: "Hadia", 
    lastName: "Hameed", 
    studentId: "10440803",
    getFileAsString,
    getFileAsJSON,
    saveStringToFile,
    saveJSONToFile
}