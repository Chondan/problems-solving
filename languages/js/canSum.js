const canSum = (targetSum, nums) => {
	if (targetSum == 0) return true;
	if (targetSum < 0) return false;

	for (const num of nums) {
		const remainder = targetSum - num;
		if (canSum(remainder, nums) === true) {
			return true;
		}
	}

	return false;
}

const canSumMemo = (targetSum, nums, memo={}) => {
	if (targetSum in memo) return memo[targetSum];
	if (targetSum == 0) return true;
	if (targetSum < 0) return false;

	for (const num of nums) {
		const remainder = targetSum - num;
		if (canSumMemo(remainder, nums, memo) === true) {
			memo[targetSum] = true;
			return true;
		}
	}

	memo[targetSum] = false;
	return false;
}

const myCanSum = (targetSum, nums) => {
	// visualization 
	// 5 -> 10, 8, 9, 12 
	// 3 -> 6, 8, 7, 10 
	// 4 -> 8, 7, 9, 11 
	// 7 -> 14, 10, 11, 12
	// loop through nums 2 time to find all possible sums between 2 numbers
	// start
	// if is in the form of possibleSum + that number return true
	// end
	// return false

	const totalSum = nums.reduce((cumulative, num) => cumulative + num, 0);
	for (const a of nums) {
		if (a > targetSum) continue;
		for (const b of [ 0, ...nums ]) {
			if ((targetSum - (a + b)) % a == 0) return true;
		}
	}
	return false;
}

// console.log(canSum(7, [5, 3, 4, 7]));
// console.log(canSum(300, [7, 14]));
// console.log(myCanSum(1, [5, 3, 4, 7]));
// console.log(myCanSum(300, [7, 14]));
console.log(canSumMemo(300, [7, 14]));