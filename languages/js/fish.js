// problem: https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/

function solution(A, B) {
    // write your code in JavaScript (Node.js 8.9.4)

    // return the number of fish that will stay alive
    // A = array of fish's sizes.
    // B = array of fish's directions.
    // When fish P and Q meet each other -> the bigger one each the smaller one

    // A = [4, 3, 2, 1, 5], B = [0, 1, 0, 0, 0]

    const n = B.length;
    let totalFish = n;

    const stack = [];
    for (let i = 0; i < n; i++) {
    	// for 0 -> look for the left -> if there are bigger fish on the left (1) -> die
    	// for 1 -> look for the right -> if there are bigger fish on the right (0) -> die
    	if (B[i] == 1) {
    		stack.push(A[i]);
    	} else {
    		while (stack.length > 0) {
    			if (A[i] > stack[stack.length - 1]) {
    				stack.pop();
    				totalFish--;
    			} else {
    				totalFish--;
    				break;
    			}
    		}
    	}
    	
    }
    return totalFish;

}

console.log(solution([4, 3, 2, 1, 5], [0, 1, 0, 0, 0])); // 2
console.log(solution([4, 3, 2, 1, 5], [0, 1, 0, 1, 0])); // 3
console.log(solution([4, 3, 2, 1, 5], [1, 1, 1, 0, 0]));
console.log(solution([0, 1], [1, 1]));