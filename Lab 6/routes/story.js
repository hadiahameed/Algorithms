const express = require('express');
const router = express.Router();

router.get("/:id", async (req,res) => {
    try {
        const data = {
            "storyTitle": "Story Title",
            "story": "Your story.\nSimply use line breaks for paragraphs.\nLike this."
        }

        res.send(data);
    }
    catch(e){
        res.status(404).json({message:"Story not found"});
    }

});

router.get("/", async (req,res) => {
    try {
        const data = {
            "storyTitle": "Story Title",
            "story": "Your story.\nSimply use line breaks for paragraphs.\nLike this."
        }

        res.send(data);    

    }
    catch(e){
        res.statusCode(500).send();

    }

});

module.exports = router;