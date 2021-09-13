const getFactors = num => {
	const factors = [];
	let i = 1;
	while (i <= num) {
		if (num % i == 0) factors.push(i);
		i++;
	}
	return factors;
}

const getRealFraction = (a, b) => {
	const factorB = getFactors(b).reverse();
	// reduce to real fraction: a/b -> x/y
	let x = a, y = b;
	for (let i = 0; i < factorB.length; i++) {
		if (x % factorB[i] == 0 && y % factorB[i] == 0) {
			x /= factorB[i];
			y /= factorB[i];
			if (y == 1) break;
		}
	}
	return [x, y];
}

const getFractionSum = (array1, array2) => {

	// a/b -> a = numerator, b = denominator
	const [numerator1, denominator1] = array1;
	const [numerator2, denominator2] = array2;

	if (denominator1 == 0 || denominator2 == 0) throw new Error("Division by zero");

	const sum = [ (numerator1*denominator2 + numerator2*denominator1), denominator1*denominator2 ];
	return getRealFraction(...sum);
}

console.log(getFractionSum([3, 5], [7, 5]));
console.log(getFractionSum([0, 5], [7, 5]));
console.log(getFractionSum([4, 5], [7, 10]));