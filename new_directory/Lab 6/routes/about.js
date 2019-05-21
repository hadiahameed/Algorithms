const express = require("express");
const router = express.Router();

router.get("/:id", async (req,res) => {
    try {
        const data = {
            "name": "Your Name",
            "cwid": "Your CWID",
            "biography": "2 biography paragraphs separated by a new line character (\n).",
            "favoriteShows": ["array", "of", "favorite", "shows"],
            "hobbies": ["array", "of", "hobbies"]
          }
          res.json(data);

    }
    catch(e){
        res.status(404).json({message: "About info not found."})

    }
});

router.get("/", async (req,res) => {
    try {
        const data = {
            "name": "Your Name",
            "cwid": "Your CWID",
            "biography": "2 biography paragraphs separated by a new line character (\n).",
            "favoriteShows": ["array", "of", "favorite", "shows"],
            "hobbies": ["array", "of", "hobbies"]
          }
          res.json(data);

    }
    catch(e){
        res.status(404).json({message: "About info not found."})

    }
});


module.exports = router;