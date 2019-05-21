
let exportedMethods = {
  palindrome_check(text) {
  if (typeof text !== "string") {
    throw "Input is not a string.";
  }
  if (!text){
    throw "Must provide an input text";
  } 
  
  //Remove unwanted characters (https://stackoverflow.com/questions/4374822/remove-all-special-characters-with-regexp)
  var exp = /[\W_]/g;
  
  text = text.toLowerCase();
  text = text.replace(exp,'');
  //An empty string is a palindrome by deafult
  //Source:http://www.cs.toronto.edu/~ahchinaei/teaching/20165/csc148/labs/lab05/ChoosingTestCases.html
  if (!text){
    throw "Must provide an input text";
  }
  if (!text.match(/^[0-9a-z]+$/)){
    throw "Input string is not alphanumeric."
  }
  
  let limit = text.length;
  if (limit==1) return 1;
  if(text.length%2==0){
    limit = limit/2;
  }
  else {
    limit = Math.floor(limit/2);
  }

  for (i = 0; i < limit; i++){
    if(text[i] !== text[text.length - i - 1]){
      return 0;
    }
    return 1;
  }
}
};

module.exports = exportedMethods;
