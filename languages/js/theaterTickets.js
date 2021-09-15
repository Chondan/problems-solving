// problem: https://app.codility.com/programmers/task/theater_tickets/

function permutation(prefix, array) {

    if (prefix.length == 3) return [prefix];
    if (array.length == 2 && prefix.length == 1) return [prefix.concat(array)];

    return array.reduce((cumulative, element, index) => {
        return cumulative.concat(permutation(prefix.concat(element), array.slice(index + 1)));
    }, []);
    
}

function isEqual(array1, array2) {
    const len1 = array1.length;
    const len2 = array2.length;
    if (len1 != len2) return false;
    let same = true;
    for (let i = 0; i < len1; i++) {
        if (array1[i] != array2[i]) {
            same = false;
            break;
        }
    }
    return same;
}

function getUniqueArray(array) {
    const transformtoString = array.map(element => element.join(''));
    const unique = [...new Set(transformtoString)];
    return unique.map(string => string.split(''));
}

function solution(A) {

    // return 0 if the number of programs is less than 3
    if (A.length < 3) return 0;
    // return 1 if all the programs are the same
    if (A.length >= 3 && [...new Set(A)].length == 1) return 1;

    const answer = permutation([], A);
    const uniqueAnswer = getUniqueArray(answer);
    return uniqueAnswer.length;
}