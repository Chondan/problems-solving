// problem: https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)

    // return -1 if the number of intersecting pairs exceeds 10,000,000
    // const disc = { id: 0, center: 0, left: center - radius, right: center + radius }
  
    
    const discs = [];
    A.forEach((radius, index) => {
        const disc = { center: index, left: index - radius, right: index + radius };
        discs.push(disc);
    });
    
    let intersects = 0;
    for (let i = 0; i < discs.length; i++) {
        for (let j = i + 1; j < discs.length; j++) {
            if (discs[i].right >= discs[j].left) {
                intersects++;
            }
        }
    }
    return intersects;
}
