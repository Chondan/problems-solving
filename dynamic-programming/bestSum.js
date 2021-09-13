const bestSum = (targetSum, nums, memo={}) => {

	if (targetSum in memo) return memo[targetSum];
	if (targetSum < 0) return null;
	if (targetSum == 0) return [];

	let ans = null;
	for (const num of nums) {
		const remainder = targetSum - num;
		let result = bestSum(remainder, nums, memo);
		if (result != null) {
			result = [...result, num];
			if (ans == null || result.length < ans.length) ans = result;
		}
	}
	memo[targetSum] = ans;
	return ans;

}

console.log(bestSum(7, [2, 3, 4, 7]));
console.log(bestSum(300, [7, 14]));