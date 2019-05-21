function error_checking(value, name){
    if(value == undefined){
        throw `${name}  is undefined.`
    }
    
    if(isNaN(value)){
        throw `The argument passed for ${name} is \"${value}\" which is not a  number.`
    }
    
    if(value<0){
        throw `${name} can't be negative.`
    }

}

const volumeOfRectangularPrism = function volumeOfRectangularPrism(length,width,height){
    var dimension = [length,width,height];
    var labels = ["length","width","height"];

    for (var i = 0; i < 3; i++){
        error_checking(dimension[i], labels[i]);

    }

    //If everything is fine, calculate the volume
    return length*width*height;
}


const surfaceAreaOfRectangularPrism = function surfaceAreaOfRectangularPrism(length,width,height){
    var dimension = [length,width,height];
    var labels = ["length","width","height"];

    for (var i = 0; i < 3; i++){
        error_checking(dimension[i], labels[i]);

    }

    //If everything is fine, calculate the surface area
    return 2*(width*length+height*length+height*width);
}

const volumeOfSphere = function volumeOfSphere(radius){
    var label = "radius";
    error_checking(radius, label);

    //If everything is fine, calculate the volume
    return (4/3)*Math.PI*Math.pow(radius,3);

}

const surfaceAreaOfSphere = function surfaceAreaOfSphere(radius){

    var label = "radius";
    error_checking(radius, label);

    //If everything is fine, calculate the surface area
    return 4*Math.PI*Math.pow(radius,2);

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