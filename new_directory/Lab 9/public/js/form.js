(function() { 
  function palindromeChecker(text) {
    if (typeof text !== "string") throw "Must provide a string";
    if (!text) throw "Must provide an input text";
    //Remove unwanted characters (https://stackoverflow.com/questions/4374822/remove-all-special-characters-with-regexp)
    var exp = /[\W_]/g;
    text = text.toLowerCase();
    text = text.replace(exp,'');
    //An empty string is a palindrome by deafult
    //Source:http://www.cs.toronto.edu/~ahchinaei/teaching/20165/csc148/labs/lab05/ChoosingTestCases.html
    if (!text) throw "Must provide an input text";
    
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
    }
    return 1;
  }

  const staticForm = document.getElementById("static-form");

  if (staticForm) {
    // We can store references to our elements; it's better to
    // store them once rather than re-query the DOM traversal each time
    // that the event runs.
    const phrase = document.getElementById("phrase");

    const errorContainer = document.getElementById("error-container");
    const errorTextElement = errorContainer.getElementsByClassName(
      "text-goes-here"
    )[0];

    const resultContainer = document.getElementById("attempts");

    // We can take advantage of functional scoping; our event listener has access to its outer functional scope
    // This means that these variables are accessible in our callback
    staticForm.addEventListener("submit", event => {
      event.preventDefault();

      try {
        // hide containers by default
        errorContainer.classList.add("hidden");

        // Values come from inputs as strings, no matter what :(
        const palindromePhrase = phrase.value;

        const result = palindromeChecker(palindromePhrase);
        var li = document.createElement("li");
        li.innerHTML = palindromePhrase;
        if (result == 1) {
          li.setAttribute("class","is-palindrome");
          $("ol#attempts").append(li);
        }
        else {
          li.setAttribute("class","not-palindrome");
          $("ol#attempts").append(li);
        }

        resultContainer.classList.remove("hidden");
      } catch (e) {
        const message = typeof e === "string" ? e : e.message;
        errorTextElement.textContent = e;
        errorContainer.classList.remove("hidden");
      }
    });
  }
})();
