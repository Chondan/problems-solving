// problem: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

function setCounters(N, value) {
    const counters = [];
    for (let i = 0; i < N; i++) {
        counters.push(value);
    }
    return counters;
}

function solution(N, A) {
    // write your code in JavaScript (Node.js 8.9.4)

    // counters = [0, 0, 0, 0, 0] N = 5
    // 1. A[K] = X -> counters[X] += 1;
    // 2. A[K] = N + 1 
    //    max = max(counters);
    //    set all counters to max;

    let counters = setCounters(N, 0);
    
    A.forEach(element => {
        if (element == (N + 1)) {
            const max = Math.max.apply(null, counters);
            counters = setCounters(N, max);        
        } else {
            counters[element - 1] += 1;
        }
    });
    return counters;
}
