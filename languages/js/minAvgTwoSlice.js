// problem: https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    // array = [4, 2, 2, 5, 1, 5, 8];
    // prefixSum at 0 = [4, 6, 8, 13, 14, 19, 27]; avg = [4/1, 6/2, 8/3, 13/4, 14/5, 19/6, 27/7];
    // prefixSum at 1 = [2, 4, 9, 10, 15, 23]; avg = [2/1, 4/2, 9/3, 10/4, 15/5, 23/6]
    // prefixSum at 2 = [2, 7, 8, 13, 21]; avg = [2/1, 7/2, 8/3, 13/4, 21/5]
    // prefixSum at 3 = [5, 6, 11, 19];
    // prefixSum at 4 = [1, 6, 14];
    // prefixSum at 5 = [5, 13];
    // prefixSum at 6 = [8]

    const N = A.length; // N = 7, i = [0, 5]
    let pos;
    let min = Number.MAX_VALUE;
    for (let i = 0; i < N - 1; i++) {
        const prefixSum = [];
        let sum = 0;
        for (let j = i; j < N; j++) { // i = 0, j = 0 to 6
            sum += A[j];
            prefixSum.push(sum);
        }

        prefixSum.forEach((sum, index) => {
            if (index > 0) {
                const newMin = sum / (index + 1);
                if (newMin < min) {
                    min = newMin;
                    pos = i;
                }
            }
        });
    }
    return pos;
}
