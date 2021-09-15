const getSum = n => {
	const str = n + '';
	return str.split('').reduce((cumulative, val) => cumulative + (+val), 0);
}

const getReverse = array => {
	if (array.length == 1) return [array[0]];
	return [ ...getReverse(array.slice(1)), array[0]];
}

const solution = n => {

	const sum = getSum(n);
	const digits = (n + '').split('').map(str => +str);
	const reverseDigit = getReverse(digits);
	const copyReverseDigit = [...reverseDigit, 0, 0, 0, 0, 0, 0];
	
	let remainder = sum;
	let i = 0;
	for (; i < reverseDigit.length; i++) {
		const digit = reverseDigit[i];
		if (digit + remainder <= 9) {
			copyReverseDigit[i] = digit + remainder;
			remainder -= remainder;
			break;
		} else {
			const add = 9 - digit;
			copyReverseDigit[i] = 9;
			remainder -= add;
		}
	}

	while (remainder > 0) {
		if (remainder <= 9) {
			copyReverseDigit[i] = remainder;
			remainder -= remainder;
		} else {
			const add = 9;
			copyReverseDigit[i] = add;
			remainder -= add;
		}
		i++;
	}

	return +getReverse(copyReverseDigit).join('');
}

console.log(solution(99));
console.log(solution(29));
console.log(solution(500));
console.log(solution(120));
console.log(solution(1));
console.log(solution(14));
console.log(solution(499));
console.log(solution(435));
console.log(solution(124));