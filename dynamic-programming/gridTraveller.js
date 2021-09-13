const gridTraveller = (n, m) => {
	if (n == 0 || m == 0) return 0;
	if (n == 1 && m == 1) return 1;
	return gridTraveller(n-1, m) + gridTraveller(n, m-1);
}

const gridTravellerMemo = (n, m, memo={}) => {
	// gridTraveller(a, b) = gridTraveller(b, a)
	// are the args in the memo
	const key = n + ',' + m; // m = 42, n = 3 -> key = '42,3'

	if (key in memo) return memo[key];
	if (n == 0 || m == 0) return 0;
	if (n == 1 && m == 1) return 1;

	memo[key] = gridTravellerMemo(n-1, m, memo) + gridTravellerMemo(n, m-1, memo);
	return memo[key];
}

console.log(gridTraveller(3, 3));
console.log(gridTravellerMemo(18, 18));