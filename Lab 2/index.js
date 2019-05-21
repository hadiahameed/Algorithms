const geometry = require("./geometry");
const utilities = require("./utilities");

//******GEOMETRY.JS******//
    //+++++volumeOfRectangularPrism+++++//
    console.log("\n-------------Volume Of Rectangular Prism-------------\n");
    //CASE I: Undefined variable
    try{
        console.log(geometry.volumeOfRectangularPrism(10,10)); //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    //CASE II: Correct float arguments
    try{
        console.log(geometry.volumeOfRectangularPrism(2.5,2,2.5)) //should return 12.5 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE III: One of the dimensions is negative
    try{
        console.log(geometry.volumeOfRectangularPrism(-10,10,10)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE IV: One of the dimensions is a string
    try{
        console.log(geometry.volumeOfRectangularPrism(10,"ten",10)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE V: All three dimensions are numbers given as strings
    try{
        console.log(geometry.volumeOfRectangularPrism("2.5","2","2.5")) //should return 12.5*/
    }
    catch(e){
        console.log(e);
    }
        

  
    //+++++surfaceAreaOfRectangularPrism+++++//
    console.log("\n-------------Surface Area Of Rectangular Prism-------------\n");
    //CASE I: Undefined variable
    try{
        console.log(geometry.surfaceAreaOfRectangularPrism(10,10)); //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    //CASE II: Correct float arguments
    try{
        console.log(geometry.surfaceAreaOfRectangularPrism(2.5,2,2.5)) //should return 32.5 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE III: One of the dimensions is negative
    try{
        console.log(geometry.surfaceAreaOfRectangularPrism(-10,10,10)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE IV: One of the dimensions is a string
    try{
        console.log(geometry.surfaceAreaOfRectangularPrism(10,"ten",10)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE V: All three dimensions are numbers given as strings
    try{
        console.log(geometry.surfaceAreaOfRectangularPrism("2.5","2","2.5")) //should return 32.5*/
    }
    
    catch(e){
        console.log(e);
    }
        
    //+++++volumeOfSphere+++++//
    console.log("\n-------------Volume Of Sphere-------------\n");
    //CASE I: Undefined variable
    try{
        console.log(geometry.volumeOfSphere()); //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    //CASE II: Correct float arguments
    try{
        console.log(geometry.volumeOfSphere(2.5)) //should return 65.45 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE III: One of the dimensions is negative
    try{
        console.log(geometry.volumeOfSphere(-2.5)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE IV: One of the dimensions is a string
    try{
        console.log(geometry.volumeOfSphere("ten")) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE V: All three dimensions are numbers given as strings
    try{
        console.log(geometry.volumeOfSphere("2.5")) //should return 65.45*/
    }
    
    catch(e){
        console.log(e);
    }

    //+++++surfaceAreaOfSphere+++++//
    console.log("\n-------------Surface Area Of Sphere-------------\n");
    //CASE I: Undefined variable
    try{
        console.log(geometry.surfaceAreaOfSphere()); //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    //CASE II: Correct float arguments
    try{
        console.log(geometry.surfaceAreaOfSphere(2.5)) //should return 78.54 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE III: One of the dimensions is negative
    try{
        console.log(geometry.surfaceAreaOfSphere(-2.5)) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE IV: One of the dimensions is a string
    try{
        console.log(geometry.surfaceAreaOfSphere("ten")) //should return an error statement 
    }
    catch(e){
        console.log(e);
    }
    
    //CASE V: All three dimensions are numbers given as strings
    try{
        console.log(geometry.surfaceAreaOfSphere("2.5")) //should return 78.54*/
    }
    
    catch(e){
        console.log(e);
    }
//******UTILITIES.JS******//
    //+++++deepEquality+++++//
  console.log("\n-------------Deep Equality-------------\n");
        const obj1 = {};
        const obj2 = {};
        const obj3 = {a: [1, 2], b:2, c:3, d:4};
        const obj4 = {b:2, a: [1, 2], c:3, d:4};
        const obj5 = {b:2, c: 4, d:3, a: {aa: 1, bb:1}};
        const obj6 = { a: {aa: 1, bb:1}, b:2, c: 4, d:3};
        const obj7 = { a: "element a", b:2};
        const obj8 = { a: "element a", b:2};
        const string1 = "This is Lab2";
        const array1  = ["a","b","c"];  
        //CASE I: DIFFERENT ORDER OF ELEMENTS BUT EQUAL
        try{                                                       
            console.log(utilities.deepEquality(obj1, obj2)); // should return true
        }
        catch(e){
            console.log(e);
        }
        //CASE II: ARRAY ELEMENTS INSIDE THE OBJECT
        try{                                                       
            console.log(utilities.deepEquality(obj3, obj4)); // should return true
        }
        catch(e){
            console.log(e);
        }
        //CASE III: NESTED OBJECTS, DIFFERENT ORDER BUT EQUAL
        try{                                                       
            console.log(utilities.deepEquality(obj5, obj6)); // should return true
        }
        catch(e){
            console.log(e);
        }
        //CASE III: STRING AS AN ELEMENT
        try{                                                       
            console.log(utilities.deepEquality(obj7, obj8)); // should return true
        }
        catch(e){
            console.log(e);
        }
        //CASE IV: STRING PASSED AS AN ARGUMENT
        try{                                                       
            console.log(utilities.deepEquality(string1, obj3)); // should return an error statement
        }
        catch(e){
            console.log(e);
        }
        //CASE V: ARRAY PASSED AS AN ARGUMENT
        try{                                                       
            console.log(utilities.deepEquality(array1, obj3)); // should return an error statement
        }
        catch(e){
            console.log(e);
        }
       

    //+++++uniqueElements+++++//
    console.log("\n-------------Unique Elements-------------\n");
        
        const arr1 = [1,2,3,4,5];
        const arr2 = [[7,3], [7,3], [3,8], [7,3], [7,3], [1,2]];
        const arr3 = [{ "name": "Joe", "age": 25 },
          { "name": "Joe", "age": 25 },  
          { "name": "Ken", "age": 32 },  
          { "name": "Dan", "age": 30 }];
        const arr4 = ["a","1",2,2,6,"a"]    
        const string2 = "hi";
        const num1 = 09;  
        
        //CASE I: SIMPLE ARRAY
        try{
        console.log(utilities.uniqueElements(arr1)); // should return 5
        }
        catch(e){
            console.log(e);
        }
        //CASE II: MULTI-DIMENSIONAL ARRAY
        try{
            console.log(utilities.uniqueElements(arr2)); // should return 3
        }
        catch(e){
            console.log(e);
        }
        //CASE III: ARRAY WITH OBJECTS
        try{
            console.log(utilities.uniqueElements(arr3)); // should return 3
        }
        catch(e){
            console.log(e);
        }
        //CASE IV: ARRAY WITH ELEMENTS OF DIFFERENT DATA TYPES
        try{
            console.log(utilities.uniqueElements(arr4)); // should return 4
        }
        catch(e){
            console.log(e);
        }
        //CASE V: PASSING A STRING
        try{
            console.log(utilities.uniqueElements(string2)); // should return an eror statement
        }
        catch(e){
            console.log(e);
        }

    //+++++countOfEachCharacterInString+++++//
    console.log("\n-------------Count of each character in a string-------------\n");
        
    const str1 = "Hello, the pie is in the oven";
    const str2 = "A a B b C c D d E e"
    const str3 = "! @ # $ % ! @ # $ %"
    
    //CASE I: UNDEFINED ARGUMENT
    try{
    console.log(utilities.countOfEachCharacterInString()); //should return an error statement
    }
    catch(e){
        console.log(e);
    }
    //CASE II: DIFFERENT DATATYPE
    try{
        console.log(utilities.countOfEachCharacterInString(arr1)); // should return an error statement
    }
    catch(e){
        console.log(e);
    }
    //CASE III: SIMPLE STRING
    try{
        console.log(utilities.countOfEachCharacterInString(str1)); 
    }
    catch(e){
        console.log(e);
    }
    //CASE IV: UPPER CASE AND LOWER CASE
    try{
        console.log(utilities.countOfEachCharacterInString(str2));
    }
    catch(e){
        console.log(e);
    }
    //CASE V: STRING OF SPECIAL CHARACTERS
    try{
        console.log(utilities.countOfEachCharacterInString(str3)); // should return an eror statement
    }
    catch(e){
        console.log(e);
    }


        