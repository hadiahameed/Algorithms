const express = require("express");
const bodyParser = require("body-parser");
const cookieParser = require("cookie-parser");
const userData = require("./users");
const bcrypt = require("bcrypt");

const app = express();

app.use(cookieParser());
app.use(bodyParser.json());

const exphbs = require("express-handlebars");
app.use(bodyParser.urlencoded({ extended: true }));

app.engine("handlebars", exphbs({ defaultLayout: "main" }));
app.set("view engine", "handlebars");

// GET
app.get('/', async (req, res) => {
  if (req.cookies.AuthCookie) {
    res.redirect("/private");
  }
  else {
    res.render("login",{});
  }
});

//GET for login
app.post('/login', async (req, res) => {
  
  const userMethods = userData;
  let user = req.body;
  //No username and password provided 
  if (!user.username || !user.password){
    res.render("login", {
    hasErrors: true,
    errors: "Username and password not provided!",
    });
    return;
  }

  let username = user.username;
  let password = user.password;
  let id = false;
  let compare = false;
  try {
    id = await userMethods.findUser(username);
  }
  catch (e) {
    console.log(e);
  }

  //No user with that username
  if (id === false){
    res.render("login", {
    hasErrors: true,
    errors: "User not found!",
    });
    return;
  }
  
  //if user present, check his/her password
  else {
    try {
      const hashedPassword = await userMethods.getPassword(id);
      try {
        compare = await bcrypt.compare(password,hashedPassword);
      }
      catch (e) {
        console.log(e)
      }
      if (compare === false){
        res.render("login", {
        hasErrors: true,
        errors: "Password mismatch!",
        });
        return;
      }
    }
    catch (e) {
      console.log(e)
    }
    

  }

  if (id != false&&compare==true){
    const now = new Date();
    const expiresAt = new Date();
    expiresAt.setHours(expiresAt.getHours() + 1);
    res.cookie("AuthCookie", username, now.toString(), { expires: expiresAt }); 
    res.redirect("/private");
  }
  
});

//AUTHENTICATION MIDDLEWARE
app.use("/private", function(request, response, next) {
  if (request.cookies.AuthCookie) {
    next();
  }
  else {
    response.status(403).render("profile", {
      hasErrors: true,
      error: "The user is not logged in.",
    });
  }

});

//GET for private
app.get('/private', async (req, res) => {
  const userMethods = userData;
  let username = req.cookies.AuthCookie;;

  firstName = '';
  lastName = '';
  profession = '';
  bio = '';
  let id = false;
  try {
    id = await userMethods.findUser(username);
  }
  catch (e) {

  }

  if (id!=false){
    try {
      username =  await userMethods.getUsername(id);
    }
    catch (e) {

    }
    try {
      firstName = await userMethods.getFirstname(id);
    }
    catch (e) {
      
    }
    try {
      lastName = await userMethods.getLastname(id);
    }
    catch (e) {
      
    }
    try {
      profession = await userMethods.getProfession(id);
    }
    catch (e) {
      
    }
    try {
      bio = await userMethods.getBio(id);
    }
    catch (e) {
      
    }  
    
  }

  res.render("profile", {
    hasErrors: false,
    loggedOut: false,
    username: username,
    firstName: firstName,
    lastName: lastName,
    profession: profession,
    bio: bio
  });
});

// GET for logout
app.get('/logout', async (req, res) => {
  const anHourAgo = new Date();
  anHourAgo.setHours(anHourAgo.getHours() - 1);
  res.clearCookie("AuthCookie");
  res.render("profile",{
    loggedOut: true
  });
});

app.use("*", (req, res) => {
  res.redirect("/");
});

app.listen(3000, function() {
  console.log(
    "Your server is now listening on port 3000! Navigate to http://localhost:3000 to access it"
  );
  if (process && process.send) process.send({done: true}); // ADD THIS LINE
});
