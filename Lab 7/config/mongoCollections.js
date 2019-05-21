const dbConnection = require("./mongoConnection");


/*Allows user to have one reference per app*/
const getCollectionFn = collection => {
	let _col = undefined;

	return async () => {
		if (!_col) {
			const db = await dbConnection();
			_col = await db.collection(collection);
		}

		return _col;
	};	
};

/*The collections can be listed here*/
module.exports = {
	recipes: getCollectionFn("recipes")
};