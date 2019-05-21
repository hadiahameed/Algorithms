const express = require('express');
const router = express.Router();

router.get("/:id", async (req,res) => {
    try {
        const data = [
            {
              "schoolName": "University of Engineering & Technology",
              "degree": "Electrical Engineering, BS",
              "favoriteClass": "Digital Signal Processing",
              "favoriteMemory": "Afternoon strolls on campus."
            },

            {
                "schoolName": "Kinnaird College for Women",
                "degree": "Intermediate",
                "favoriteClass": "Chemistry",
                "favoriteMemory": "Sufi night shows."
            },
            {
                "schoolName": "Beaconhouse School System",
                "degree": "Olevels",
                "favoriteClass": "Urdu",
                "favoriteMemory": "Inter-section basketball matches."
              }

        ]

        res.send(data);
    }
    catch(e){
        res.status(404).json({message:"Story not found"});
    }

});

router.get("/", async (req,res) => {
    try {
        const data = [
            {
              "schoolName": "First School Name",
              "degree": "First School Degree",
              "favoriteClass": "Favorite class in school",
              "favoriteMemory": "A memorable memory from your time in that school"
            },

            {
                "schoolName": "First School Name",
                "degree": "First School Degree",
                "favoriteClass": "Favorite class in school",
                "favoriteMemory": "A memorable memory from your time in that school"
            },
            {
                "schoolName": "First School Name",
                "degree": "First School Degree",
                "favoriteClass": "Favorite class in school",
                "favoriteMemory": "A memorable memory from your time in that school"
              }
        ]
        res.send(data);    

    }
    catch(e){
        res.statusCode(500).send();
    }
});

module.exports = router;