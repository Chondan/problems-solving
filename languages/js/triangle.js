// problem: https://app.codility.com/programmers/lessons/6-sorting/triangle/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    // array = [10, 2, 5, 1, 8, 20]
    // sorted = [20, 10, 8, 5, 2, 1]

    // 10, 8 -> x = {3, 4, 5, 6, 7, 8, 9, ..., 17}
    // x + 8 > 10 -> x > 2
    // x + 10 > 8 -> x > -2
    // x < 10 + 8 -> x < 18
    // x is in range (2, 18) -> (a - b, a + b)
    // we need to minimize a - b and maximize a + b
    // so b = a - 1 or a and b is the most 2 elements in array

    // e.g. a = 20, b = 10
    // c is in range (10, 30)

    // loop
    // find range -> (a, b) if A[i + 2] <= a return false

    // [50, 10, 5, 1]

    const N = A.length;
    const sorted = A.sort((a, b) => b - a);
    
    if (N < 3) return 0;
    
    let triangle = false;
    for (let i = 0; i < N - 2; i++) {
        const a = sorted[i] - sorted[i + 1];
        const b = sorted[i] + sorted[i + 1];
        if (sorted[i + 2] > a) triangle = true;
        if (triangle) break;
    }
    
    return triangle ? 1 : 0;
}
