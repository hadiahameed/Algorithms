const text_Metrics = require('./text_Metrics')
const fileData = require('./fileData');
const files = ["text.txt"];

async function main(){
    for (var i in files){

        //checking filename and extension
        if(typeof files[i] != 'string'){
            throw `${files[i]} is not a string.`;
        }
        let extension = files[i].split('.');
        extension = extension[extension.length - 1];
        if(extension!='txt'){
            throw `${files[i]} is not a text file.`
        }

        const fileName = files[i];                                     //"chapter1.txt"
        let fileHeader = fileName.split('.');       
        fileHeader = fileHeader.slice(0,fileHeader.length-1);          //"chapter1"
        const jsonPath = fileHeader+".result.json"                     //"chapter.result.json"

        //Check if chapter1.result.json exists; if it does, run getFileAsJSON and print the resulting object
        console.log(`Checking if JSON file for ${files[i]} already exists...`)
        try{
            let obj = await fileData.getFileAsJSON(jsonPath);
            if(typeof obj == 'object'){
                console.log(`JSON file for ${files[i]} exists. Its contents are:\n`)

                console.log(obj)
            }
            //If no result is found, perform getFileAsString(chapter1.txt)
            else{
                
    
                    console.log(`JSON file for ${files[i]} does not exist. Reading ${fileName} now...`)
                    try{
                        //Run the text metrics
                        const stringFile = await fileData.getFileAsString(fileName);
                        const JSONObj = text_Metrics.createMetrics(stringFile);
                        //and store those results in chapter1.result.json
                        try {                            
                            await fileData.saveJSONToFile(jsonPath,JSONObj);
                            //Print the resulting metrics
                            console.log(JSONObj)
                        }
                        catch(e){
                            throw `Error saving file: ${e}`;
                        }
                    }
                    catch(e){
                        throw `Error reading file ${e}`
                    }
            }
     
        }
        catch(e){
            throw `Error reading JSON:${e}`
        }
           }
    return null

}

main().catch(err => {
    console.log(err);
  });
  