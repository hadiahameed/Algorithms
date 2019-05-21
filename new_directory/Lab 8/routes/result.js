const express = require("express");
const router = express.Router();
const data = require("../data");
const resultData = data.result;


router.post("/", async (req, res) => {
  let palindromeData = req.body;
  let errors = [];
  if (!palindromeData["text-to-test"]) {
    errors.push("No text provided");
  }

  if (errors.length > 0) {
    res.status(400).render("result/index", {
      errors: errors,
      hasErrors: true,
      title: "The Palindrome Results!", 
      heading: "The Palindrome Results!"
    });
    return;
  }

  try {
    let message = '';
    let assigned_class = "failure";
    const result = await resultData.palindrome_check(palindromeData["text-to-test"]);
    
    if (result == 0){
      message = 'The input is not a palindrome';
    }
    else if (result == 1){
      assigned_class = "success";
      message = 'The input is a palindrome';
    }
    res.render("result/index", {title: "The Palindrome Results!", heading: "The Palindrome Results!", assigned_class: assigned_class, text_to_test: palindromeData["text-to-test"], message: message, result: result});
  } catch (errors) {
    res.status(500).render("result/index", {
      errors: errors,
      hasErrors: true,
      title: "The Palindrome Results!", 
      heading: "The Palindrome Results!"
    });
  }
});

module.exports = router;

