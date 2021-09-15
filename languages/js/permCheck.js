// problem: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    // permutation return 1
    // if not permutation return 0
    const N = A.length;
    let sum = (N * (N + 1)) / 2;

    const history = {};
    for (let i = 0; i < N; i++) {
        if (history[A[i]]) {
            sum = -1;
            break;
        } else {
            history[A[i]] = true;
            sum -= A[i];
        }
    }

    return sum == 0 ? 1 : 0;
}
