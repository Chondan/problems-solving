// Assumption
// 1. case-insensitive

const removeDuplicate = str => {
	const memo = {}; // memo character
	const removed = {}; // memo removed character
	for (char of str.toLowerCase()) {
		if (char in memo) removed[char] = true;
		else memo[char] = true;
	}

	const remainingChars = Object.keys(memo).filter(char => !(char in removed));
	return remainingChars.join('');
}

console.log(removeDuplicate("Hello World"));
console.log(removeDuplicate("Hello World, How are you doing?"));