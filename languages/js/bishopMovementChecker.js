const charToNum = (char) => {
    const asciiBeforeLowerA = 96;
    const asciiOfChar = char.charCodeAt(0);
    return asciiOfChar - asciiBeforeLowerA;
}

const sumOfPosition = (pos /* '11' -> 2 */) => {
    return Number(pos[0]) + Number(pos[1]);
}

const getRowCol = (pos) => {
    return {row: Number(pos[0]), col: Number(pos[1])};
}

// return true if possible otherwise false
const bishop = (startPos, endPos, num_Moves) => {
    const isStillInSamePosition = startPos === endPos;
    if (isStillInSamePosition) return true;

    // Convert char to number e.g. 'a1' -> '11'
    const adjustStartPos = startPos.replace(startPos[0], charToNum(startPos[0]));
    const adjustEndPos = endPos.replace(endPos[0], charToNum(endPos[0]));
    
    /*
    --- Check if startPos and endPos are in the same color of cell of chess table ---
    Sum up row and col position of adjustStartPos and adjustEndPos e.g. 'a1' -> '11' -> 2, 'b4' -> '24' -> 6
    if the sum of startPost and endPos all both even or odd then -> we can go from startPos to endPos in just 2 moves 
    */
    const isStartAndEndInSameColorCell = (sumOfPosition(adjustStartPos) % 2) - (sumOfPosition(adjustEndPos) % 2) === 0;
    const canGoWith2Moves = isStartAndEndInSameColorCell && num_Moves >= 2;

    /* 
    --- Check if startPos and endPos are in the same diagonal -> we can go from startPos to endPos in just 1 moves 
    if |row1 - row2| = |col1 - col2| -> both position are in the same diagonal
    */
    const {row: row1, col: col1} = getRowCol(adjustStartPos);
    const {row: row2, col: col2} = getRowCol(adjustEndPos);
    const isStartAndEndInSameDiagonal = Math.abs(row1 - row2) === Math.abs(col1 - col2);
    const canGoWith1Move = isStartAndEndInSameDiagonal && num_Moves >= 1;

    return canGoWith1Move || canGoWith2Moves;
}

console.log(bishop('a1', 'b4', 2)); // true
console.log(bishop('a1', 'b5', 5)); // false
console.log(bishop('f1', 'f1', 0)); // true
console.log(bishop('e6', 'a1', 2)); // false
console.log(bishop('a3', 'b2', 1)); // true