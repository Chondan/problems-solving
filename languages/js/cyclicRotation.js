// problem: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

function solution(A, K) {
    // write your code in JavaScript (Node.js 8.9.4)

    if (K < 0 || K > 100) throw new Error('Out of index');
    const N = A.length;
    if (N < 0 || N > 100) throw new Error('Out of index');

    // shift r k time is equal to shift l A.length - k time
    const shiftL = A.length - (K % N);
    const frontArray = A.slice(shiftL);
    const backArray = A.slice(0, shiftL);

    return [...frontArray, ...backArray];
    
}