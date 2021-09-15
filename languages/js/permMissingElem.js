// problem: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    if (A.length > 100000) throw new Error('Out of condition');
    
    const n = A.length + 1;
    const expectedSum = n * (n + 1) / 2;
    const actualSum = A.reduce((total, val) => total + val, 0);

    return expectedSum - actualSum;
}
