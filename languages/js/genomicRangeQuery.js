// problem: https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

function solution(S, P, Q) {
    // write your code in JavaScript (Node.js 8.9.4)

    // A = 1, C = 2, G = 3, T = 4
    // find minimal impact factor in a particular part of the given DNA sequences
    
    // S = CAGCCTA
    // P = [2, 5, 0]
    // Q = [4, 5, 6]


    // transfrom S in the integer shape -> s = 2 1 3 2 2 4 1
    const impacFactor = {
        A: 1, C: 2, G: 3, T: 4
    };
    
    const answer = [];
    const lenP = P.length;
    for (let i = 0; i < lenP; i++) {
        let start = P[i];
        const end = Q[i] + 1;
        let min = 5;
        while (start < end) {
            const newMin = impacFactor[S[start]];
            if (newMin < min) min = newMin;
            start += 1;
        }
        answer.push(min);
    }
    return answer;
}
