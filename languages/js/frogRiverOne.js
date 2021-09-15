// problem: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

function solution(X, A) {
    // write your code in JavaScript (Node.js 8.9.4)

    if (A.length < X) return -1;
    
    const appeared = {};
    for (let i = 1; i <= X; i++) {
        appeared[i] = i;
    }

    let ans = -1;
    for (let i = 0; i < A.length; i++) {
        if (appeared[A[i]]) {
            delete appeared[A[i]];
            if (Object.keys(appeared).length == 0) {
                ans = i;
                break;
            }
        }
    }
    return ans;
}
