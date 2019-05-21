
const constructorMethod = app => {
  app.get("/", (req, res) => {
    res.render("palindrome/static", {});
  });

  app.use("*", (req, res) => {
    res.redirect("/palindrome/static");
  });
};

module.exports = constructorMethod;
