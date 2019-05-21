const error_checking = function error_checking(value, name){
    var message = [];
    value = Number(value);
    if(isNaN(value)){
        answer = "The argument passed for " + name + " is not pro."
        message.push(answer);
    }
    //If length is less than zero
    else {
        if(value<0){
            answer = "The argument passed for " + name + " is \"" + value + "\" which is less than 0."
            message.push(answer);
        }
    }

    return message;

}

const volumeOfRectangularPrism = function volumeOfRectangularPrism(length,width,height){
    var alerts = [];
    var dimension = [length,width,height];
    var labels = ["length","width","height"];

    for (var i = 0; i < 3; i++){
        var error = error_checking(dimension[i], labels[i]);
        if (error.length>0){
            alerts = alerts.concat(error);
        }  

    }

    //If everything is fine, calculate the volume
    if (alerts.length == 0){
        answer = length*width*height;
        return answer;
    }
    //Otherwise return the error messages, if any.
    else
    {
        return alerts;
    }
}
const surfaceAreaOfRectangularPrism = function surfaceAreaOfRectangularPrism(length, width, height){
    var alerts = [];
    var dimension = [length,width,height];
    var labels = ["length","width","height"];

    for (var i = 0; i < 3; i++){
        var error = error_checking(dimension[i], labels[i]);
        if (error.length>0){
            alerts = alerts.concat(error);
        }  

    }

    //If everything is fine, calculate the surface area
    if (alerts.length == 0){
        //Formula reference: https://www.basic-mathematics.com/surface-area-of-a-rectangular-prism.html
        answer = 2*(width*length+height*length+height*width)
        return answer;
    }
    //Otherwise return the error messages, if any.
    else
    {
        return alerts;
    }
}

const volumeOfSphere = function volumeOfSphere(radius){
    var alerts = [];
    var dimension = radius;
    var label = "radius";
    var error = error_checking(dimension, label);
    if (error.length>0){
        alerts = alerts.concat(error);
    }  


    //If everything is fine, calculate the volume of the sphere
    if (alerts.length == 0){
        //Formula reference: https://www.mathopenref.com/spherevolume.html
        answer = (4/3)*Math.PI*Math.pow(radius,3);
        return answer;
    }
    //Otherwise return the error messages, if any.
    else
    {
        return alerts;
    }

}

const surfaceAreaOfSphere = function surfaceAreaOfSphere(radius){

    var alerts = [];
    var dimension = radius;
    var label = "radius";
    var error = error_checking(dimension, label);
    if (error.length>0){
        alerts = alerts.concat(error);
    }  


    //If everything is fine, calculate the surface area of the sphere
    if (alerts.length == 0){
        //Formula reference: https://www.mathopenref.com/spherearea.html
        answer = 4*Math.PI*Math.pow(radius,2);
        return answer;
    }
    //Otherwise return the error messages, if any.
    else
    {
        return alerts;
    }

}

module.exports = {
    firstName: "Hadia", 
    lastName: "Hameed", 
    studentId: "10440803",
    volumeOfRectangularPrism,
    surfaceAreaOfRectangularPrism,
    volumeOfSphere,
    surfaceAreaOfSphere
};