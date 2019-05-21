const express = require("express");
const router = express.Router();
const data = require("../data");
const recipeData = data.recipes;

router.get("/:id", async (req, res) => {
	try {
		const recipe = await recipeData.getRecipeById(req.params.id);
		res.json(recipe);
	} catch (e) {
		res.status(404).json({ error: "Recipe not found" });
	}
});

router.get("/", async (req, res) => {
	try {
		const recipeList = await recipeData.getAllRecipes();
		res.json(recipeList);
	} catch (e) {
		res.status(500).json({ error: e });
	}
});

router.post("/", async (req, res) => {
	const blogRecipeData = req.body;
	try {
		const { title, ingredients, steps } = blogRecipeData;
		if (!title) throw "Title missing."
		if (typeof title !== "string") throw "Title is not a string";
		if (!ingredients) throw "Ingredients missing."
		if (!Array.isArray(ingredients)) throw "Ingredient list is not an array.";
		if (!steps) throw "Steps missing."
		if (!Array.isArray(steps)) throw "Steps are not passed as an array.";

		const newRecipe = await recipeData.addRecipe(title, ingredients, steps);

		res.json(newRecipe);
	} catch (e) {
		res.status(500).json({ error: e });
	}
});

router.put("/:id", async (req, res) => {
	if(!req.params.id) throw 'No id provided.'
	const replacingData = req.body;
	try {
		await recipeData.getRecipeById(req.params.id);
	} catch (e) {
		res.status(404).json({ error: "Recipe not found." });
	}

	try {
		const { title, ingredients, steps } = replacingData;
		if (!title) throw "Title missing."
		if (typeof title !== "string") throw "Title is not a string";
		if (!ingredients) throw "Ingredients missing."
		if (!Array.isArray(ingredients)) throw "Ingredient list is not an array.";
		if (!steps) throw "Steps missing."
		if (!Array.isArray(steps)) throw "Steps are not passed as an array.";
		const replacedRecipe = await recipeData.replaceRecipe(req.params.id, replacingData);
		res.json(replacedRecipe);
	} catch (e) {
		res.status(500).json({ error: e });
	}
});

router.patch("/:id", async (req, res) => {
	const updatedData = req.body;
	try {
		await recipeData.getRecipeById(req.params.id);
	} catch (e) {
		res.status(404).json({ error: "Recipe not found" });
	}

	try {
		const updatedRecipe = await recipeData.updateRecipe(req.params.id, updatedData);
		res.json(updatedRecipe);
	} catch (e) {
		res.status(500).json({ error: e });
	}
});

router.delete("/:id", async (req, res) => {
	try {
		await recipeData.getRecipeById(req.params.id);
	} catch (e) {
		res.status(404).json({ error: "Recipe not found." });
	}
	try {
		await recipeData.removeRecipe(req.params.id);
		res.status(200).json({ success: "Recipe deleted!" });
	} catch (e) {
		res.status(500).json({ error: e });
	}
});

module.exports = router;