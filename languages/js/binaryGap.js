// problem: https://app.codility.com/programmers/lessons/1-iterations/binary_gap/

function getBase2(N) {
    return N.toString(2);    
}

function getMaxLengthOfElement(base2) {
    
    // 20 -> 10100 (return 1)
    const answers = [];
    let count = 0;
    for (let i = 0; i < base2.length; i++) {
        if (base2[i] == '1') {
            answers.push(count);
            count = 0;
        } else {
            count += 1;
        }
    }
    return Math.max.apply(null, answers);
}

function solution(N) {
    // write your code in JavaScript (Node.js 8.9.4)

    const base2 = getBase2(N);
    return getMaxLengthOfElement(base2);
    
}

