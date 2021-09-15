// problem: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    const countObj = {}; 
    A.forEach(val => {
        if (countObj[val]) {
            delete countObj[val];
        } else {
            countObj[val] = val;
        }
    });

    return Object.values(countObj)[0];
}