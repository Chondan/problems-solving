const countConstruct = (target, words, memo={}) => {

	if (target in memo) return memo[target];
	if (target == '') return 1;

	let count = 0;
	for (const word of words) {
		if (target.search(word) == 0) {
			const suffix = target.slice(word.length);
			const result = countConstruct(suffix, words, memo);
			count += result;
		}
	}

	memo[target] = count;
	return count;

}

console.log(countConstruct('purple', ['purp', 'p', 'ur', 'le', 'purpl']));
console.log(countConstruct('eeeeeeeef', ['e', 'ee', 'eee']));