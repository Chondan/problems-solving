// problem: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp/

function isInCondition(value) {
    return value >= 1 && value <= 1e9;
}

function solution(X, Y, D) {
    // write your code in JavaScript (Node.js 8.9.4)
    if (isInCondition(X) && isInCondition(Y) && isInCondition(D)) {
        if (X <= Y) {
            return Math.ceil((Y - X)/D)
        } else {
            throw new Error('Out of condition');
        }
    } else {
        throw new Error('Out of condition');
    }
}
