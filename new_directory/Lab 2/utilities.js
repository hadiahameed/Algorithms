function error_checking(arg, type){
    if(arg == undefined){
        throw "Input argument is undefined."
    }

    if(arg == null){
        throw "Input argument is empty."
    }
    
    if(type!="array"&&type!="object"){
        if(typeof arg!= type)
            throw `The argument passed is not a ${type}.`
    }
    else{
        if(type=="array"){
            if(!Array.isArray(arg))
            throw `The input argument is ${arg} which is not an ${type}`
        }
        else if(type=="object"){
            if(arg.constructor!=Object)
            throw `The input argument is ${arg} which is not an ${type}`;
        }
    }

}

//For deepEquality, a few clues were taken from http://adripofjavascript.com/blog/drips/object-equality-in-javascript.html 
const deepEquality = function deepEquality(obj1, obj2){
    error_checking(obj1,'object');
    error_checking(obj2,'object')
    var obj1keys = Object.getOwnPropertyNames(obj1);
    var obj2keys = Object.getOwnPropertyNames(obj2);
    if(obj1keys.length == obj2keys.length){
        //if the two objects are empty, they are equal.
        var result = true;

        //Otherwise...
        for (var i = 0; i < obj1keys.length; i++) {
            var key = obj1keys[i];

            //if obj1 is a nested object
            if(typeof obj1[key]=='object'&&obj2[key].constructor==Object)
            {
                //if obj2 is also a nested object
                if(typeof obj2[key]=='object'&&obj2[key].constructor==Object){
                
                    //recursive function
                    result = deepEquality(obj1[key],obj2[key]);
                    if(result == false)
                        return false;
                }
                //if obj1's element is an object but the corresponding element of obj2 is not.
                else
                    return false;

            }
            //objects having an array as an element
            else if(obj2[key].constructor==Array)
            {
                if(obj2[key].constructor==Array){
                    
                    var array1 = obj1[key];
                    var array2 = obj2[key];
                    //comparing array elements
                    for (var i in array1){
                        if(array1[i]!=array2[i])
                            return false;
                    }
                    result = true;
                }
                //if obj1's element is an array but the corresponding element of obj2 is not.
                else
                    return false;

            }
            //if the elements are simple datatypes, simply compare them
            else{
                if(obj1[key]!=obj2[key]){
                    return false;
                }
                else
                    var result = true;
            }
        }           
    }
    else
        return false;
    return result;
}

const uniqueElements = function uniqueElements(arr){
    
    error_checking(arr,'array');
    var obj1 = new Object();      
    for (var i in arr){
        obj1[JSON.stringify(arr[i])] = 1;
    }
    return Object.keys(obj1).length;

}

const countOfEachCharacterInString = function countOfEachCharacterInString(str){
    error_checking(str,'string');
    var charMap = new Object();
    for (var char in str){
        charMap[str[char]] = 0;
    }
    for (var char in str){
        charMap[str[char]] = charMap[str[char]]+1;
    }
    return charMap;
}



module.exports = {
    firstName: "Hadia", 
    lastName: "Hameed", 
    studentId: "10440803",
    deepEquality,
    uniqueElements,
    countOfEachCharacterInString,
}