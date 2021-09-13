const canConstruct = (target, words, memo={}) => {

	if (target in memo) return memo[target];
	if (target == '') return true;

	for (const word of words) {
		if (target.search(word) == 0) {
			const suffix = target.slice(word.length);
			const result = canConstruct(suffix, words, memo);
			if (result == true) {
				memo[target] = true;
				return true;
			}
		}
	}

	memo[target] = false;
	return false;
}

console.log(canConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd']));
console.log(canConstruct('abc', ['d', 'e', 'f', 'ab', 'c']));
console.log(canConstruct('eeeeeeeeeeeeeeeeeeef', ['e', 'ee', 'eee', 'eeee', 'eeeee']));