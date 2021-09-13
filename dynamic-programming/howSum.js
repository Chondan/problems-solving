const howSum = (targetSum, nums) => {

	if (targetSum < 0) return null;
	if (targetSum == 0) return [];

	for (const num of nums) {
		const remainder = targetSum - num;
		let result = howSum(remainder, nums);
		if (result !== null) {
			return [ ...result, num ];
		}
	}

	return null;
}

const howSumMemo = (targetSum, nums, memo={}) => {

	if (targetSum in memo) return memo[targetSum];
	if (targetSum < 0) return null;
	if (targetSum == 0) return [];

	for (const num of nums) {
		const remainder = targetSum - num;
		let result = howSumMemo(remainder, nums, memo);
		if (result !== null) {
			memo[targetSum] = [ ...result, num ];
			return memo[targetSum];
		}
	}

	memo[targetSum] = null;
	return null;
}

const howSumAllPossible = (targetSum, nums, memo={}) => {

	if (targetSum in memo) return memo[targetSum];
	if (targetSum < 0) return null;
	if (targetSum == 0) return [[]];

	const ans = [];
	for (const num of nums) {
		const remainder = targetSum - num;
		let result = howSumAllPossible(remainder, nums, memo);
		if (result != null) {
			result = result.map(r => [...r, num]);
			memo[targetSum] = result;
			ans.push(...result);
		}
	}	
	return ans;
}

// console.log(howSum(7, [5, 3, 4, 7]));
// console.log(howSum(7, [2, 4]));
// console.log(howSum(300, [7, 14]));
// console.log(howSumMemo(7, [5, 3, 4, 7]));
// console.log(howSumMemo(7, [2, 4]));
// console.log(howSumMemo(300, [7, 14]));
console.log(howSumAllPossible(7, [5, 3, 4, 7]));