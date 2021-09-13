
const lis = nums => {
	// find the longest increasing subsequence

	// [3, 1, 8, 2, 5]
	// lis(n) = 1 + lis(n-1)

	let ans = 0;
	let count = 0;
	for (let i = 1; i < nums.length; i++) {
		if (nums[i - 1] < nums[i]) ans++;
	}
	return ans == 0 ? 0 : ans + 1;

}

console.log(lis([5, 2, 8, 6, 3, 6, 9, 5]));
console.log(lis([3, 1, 8, 2, 5]));
console.log(lis([1, 2, 3, 4, 5]));
console.log(lis([5, 4, 3, 2, 1]));
console.log(lis([10, 2, 3, 9, 5]));