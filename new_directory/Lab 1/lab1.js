const questionOne = function questionOne(arr) {
    // Implement question 1 here
    array_size = arr.length;
	let running_sum = 0;
	for (i = 0; i < array_size; i++)
		running_sum = running_sum + Math.pow(arr[i],2);
	
	return running_sum
}

const questionTwo = function questionTwo(num) { 
    // Implement question 2 here
    let answer = undefined
    function fibonacci(num1){
        if (num1<1)
           return 0
           else if (num1==1)
            return 1

        else
            return fibonacci(num1-1)+fibonacci(num1-2)
    }
    answer = fibonacci(num);
    return answer
}

const questionThree = function questionThree(text) {
    // Implement question 3 here
    //Got the following line from https://stackoverflow.com/questions/6484670/how-do-i-split-a-string-into-an-array-of-characters
    let char = text.split('');

    let count = 0;
    char.forEach(letter => {
        if (letter=="a"||letter=='i'||letter=='o'||letter=='e'||letter=='u'){
            count = count + 1;
        }
      })
      return count

}

const questionFour = function questionFour(num) {
    // Implement question 4 here
    let answer = num;
    if (num==0)
        answer = 1;
    else if (num<0)
        answer = NaN
    else
        for (i=1;i<num;i++){
            answer = answer * (num-i);
        }
    return answer
}

module.exports = {
    firstName: "Hadia", 
    lastName: "Hameed", 
    studentId: "10440803",
    questionOne,
    questionTwo,
    questionThree,
    questionFour
};