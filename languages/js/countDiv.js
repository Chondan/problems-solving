// problem: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

function solution(A, B, K) {
    // write your code in JavaScript (Node.js 8.9.4)

    // [11, 14, 2] return 2 -> 12, 14
    // find a1 -> if A % 2 == 0 then a1 = A else a1 = A - 1
    // find an -> if B % 2 == 0 then an = B else an = B - 1
    // an = a1 + (n-1)d

    const a1 = A % K == 0 ? A : A - (A % K);
    const an = B % K == 0 ? B : B - (B % K);
    let n = ((an - a1)/K) + 1;
    if (A % K != 0) n -= 1;
    return n;
    
}
