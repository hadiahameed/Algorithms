const resultRoutes = require("./result");

let constructorMethod = app => {
  app.use("/result", resultRoutes);
};

module.exports = {
  result: require("./result")
};
