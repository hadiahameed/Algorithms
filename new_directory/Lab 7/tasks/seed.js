const dbConnection = require("../config/mongoConnection");
const data = require("../data/");
const recipes = data.recipes;

async function main() {

	const db = await dbConnection();
	await db.dropDatabase();

	await recipes.addRecipe(
		"Fried Eggs", 
    [
      {
        name: "Egg",
        amount: "2 eggs"
      },
      {
        name: "Olive Oil",
        amount: "2 tbsp"
      },
    ],
    [
      "First, heat a non-stick pan on medium-high until hot",
      "Add the oil to the pan and allow oil to warm; it is ready the oil immediately sizzles upon contact with a drop of water.",
      "Crack the egg and place the egg and yolk in a small prep bowl; do not crack the yolk!",
      "Gently pour the egg from the bowl onto the oil",    
      "Wait for egg white to turn bubbly and completely opaque (approx 2 min)",
      "Using a spatula, flip the egg onto its uncooked side until it is completely cooked (approx 2 min)",
      "Remove from oil and plate",
      "Repeat for second egg"
		]);
		
console.log("Done seeding database");
await db.close();

}

main();
