// Find all possible array of 3 unique indices of a 
// given n array that sum of all pointed numbers must be equal
// to a specific target

const helper = (numbers, target, memo ={}) => {
	if (target in memo) return memo[target];
	if (target < 0) return null;
	if (target == 0) return [[numbers[0]]];

	const ans = []
	for (let i = 1; i < numbers.length; i++) {
		const remain = target - i;
		let result = helper(numbers, remain, memo);
		if (result != null) {
			result = result.map(r => [...r, numbers[i]]);
			ans.push(...result);
		}
	}
	memo[target] = ans;
	return ans;
}

const threeSum = (numbers, target) => {
	let ans = helper(numbers, target);
	const memo = {};
	ans = [... new Set(ans.filter(a => a.length == 3).map(a => a.sort().join('')))];
	ans = ans.map(a => a.split('').map(num => +num));
	return ans;
}

console.log(threeSum([5, 4, 3, 2, 1], 5));