// problem: https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    const N = A.length;
    const sortedArray = A.sort((a, b) => a - b);
    
    if (sortedArray[N - 1] < 0) return 1;
    if (sortedArray[0] > 1) return 1;

    const unique = [...new Set(sortedArray)];

    let smallest = 1;
    for (let i = 0; i < unique.length; i++) {

        if (unique[i] > 0) {
            if (unique[i] == smallest) {
                smallest += 1;
            } else {
                break;
            }
        }
    }
    return smallest;
}
