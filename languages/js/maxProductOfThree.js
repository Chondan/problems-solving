// problem: https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    const len = A.length;
    const sortedArray = A.sort((a, b) => b - a); // max to min
    
    // case there are just 3 elements
    if (len == 3) return A[0] * A[1] * A[2];

    // case all elements are negative
    if (sortedArray[0] < 0) return sortedArray[0] * sortedArray[1] * sortedArray[2];

    // case all elements are positive
    if (sortedArray[0] > 0 && sortedArray[len - 1] > 0) return sortedArray[0] * sortedArray[1] * sortedArray[2];
    
    // case positve and negative values are in array
    // array = [6, 5, 2, 1, -3, -2];
    // find the exact most -> campare 6 and -2, 5 and -3
    // 1. need 3 positive value
    // 2. need 2 negative value and 1 positive value

    // sample
    // [5, 4, -1, -6, -10]
    // [4, -1, -2, -3, -4, -5] -> i point to front and j point to back (stop the loop when j == 2)
    // [1, 2, -3, -4, -5]
    // [15, 6, -1, -7, -9]
    // [-1, -2, -3, -4, -5]
    // [10, 4, -2, -3] -> quickMax = -80
    // [10, 5, -1, -20, -25] -> quickMax = -50
    // [2, -4, -5, -6]
    // [10, -1, -2, -3]
    // [6, 5, 2, 1, -2, -3]
    // [7, 4, 3, 2, 1, -3, -5]
    // [7, 6, 5, -10]
    // [7, 6, 5, 4, 3, -10]
    // [10, 3, -1, -2]

    // find quickMax by the first 3 elements of sortedArray
    // find anotherMax by below algorithm
    // compare quickMax and anotherMax -> return the greater value
    
    const quickMax = sortedArray[0] * sortedArray[1] * sortedArray[2];
    const anotherMax = sortedArray[0] * sortedArray[len - 1] * sortedArray[len - 2];

    return  anotherMax > quickMax ? anotherMax : quickMax;
}
