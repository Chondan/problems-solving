// problem: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    const len = A.length;

    let sumL = A[0];
    let sumR = 0;
    for (let i = 1; i < len; i++) {
        sumR += A[i];
    }
    let minDiff = Math.abs(sumL - sumR);
   
    for (let i = 1; i < len - 1; i++) {
        sumL += A[i];
        sumR -= A[i];

        const diff = Math.abs(sumL - sumR);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    return minDiff;
}
