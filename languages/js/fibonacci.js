const fibRecur = n => {
	if (n <= 2) return 1;
	return fibRecur(n-1) + fibRecur(n-2);
}

const fibMemo = n => {
	// memoization
	const fibs = {};
	for (let i = 1; i <= n; i++) {
		if (i == 1 || i == 2) {
			fibs[i] = 1;
		} else {
			fibs[i] = fibs[i-1] + fibs[i-2];
		}
	}
	return fibs[n];
}

const fibMemoAndRecur = (n, memo={}) => {
	if (n in memo) return memo[n];
	if (n <= 2) return 1;
	memo[n] = fibMemoAndRecur(n-1, memo) + fibMemoAndRecur(n-2, memo);
	return memo[n];
}

console.time();
console.log(fibMemoAndRecur(50));
// console.log(fibMemo(50));
// console.log(fibRecur(50));
console.timeEnd();