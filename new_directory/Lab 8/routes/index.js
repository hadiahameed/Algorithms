const resultRoutes = require("./result");

const constructorMethod = app => {
  let title = "The Best Palindrome Checker in the World!";
  app.use("/result", resultRoutes);
  app.get("/", (req, res) => {
    res.render("home", {title: title, heading: title});
  });

  app.use("*", (req, res) => {
    res.render("home", {title: title, heading: title});
  });
};

module.exports = constructorMethod;
