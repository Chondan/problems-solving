const gen = (str, open, close, n) => {

	// for balanced parenthesis -> there are n "open parenthesis" and n "close parenthesis"
	// e.g. "((()))"
	// So, starting from an empty string.
	// There are 2 choices to consider.
	// 1. If the number of "open parenthesis" is less than n -> can add "(" to the string
	// 2. If the number of "open parenthesis" is more than the number of "close parenthesis" -> can add ")" to the string
	
	if (close == n) return [str];

	const ans = [];
	if (open < n) {
		const result = gen(str + "(", open+1, close, n);
		ans.push(...result);
	}
	if (open > close) {
		const result = gen(str + ")", open, close+1, n);
		ans.push(...result);
	}
	return ans;

}

const generateParentheses = n => {
	return gen("", 0, 0, n);
}

console.log(generateParentheses(1));
console.log(generateParentheses(2));
console.log(generateParentheses(3));
console.log(generateParentheses(4));
console.log(generateParentheses(5));
console.log(generateParentheses(6));
