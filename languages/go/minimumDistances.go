package main
import (
    "fmt"
    "math"
)

func main() {
    var a = []int32{3,2,1,2,3}
    var ans = minimumDistances(a)
    fmt.Println("ans:", ans)
}

/* 
Analysis

Will use a hash map to store number -> recently index
- By default in go, map[x] = 0, so we will store recently index in the form of index + 1
- if map[x] = 0 -> skip; else calculate mindiff from abs(currentIndex - recentlyIndex)

*/
func minimumDistances(a []int32) int32 {
    var lenA int32 = int32(len(a))
    var minDistance int32 = lenA
    var memo = make(map[int32]int32)
    var i int32 = 0

    for ; i < lenA; i++ {
	var num int32 = a[i]
	var syntheticCurIndex = i + 1
	if memo[num] == 0 {
	    // Update recentlyIndex
	    memo[num] = syntheticCurIndex
	    continue
	}

	var recentlyIndex = memo[num]
	// Update minDistance
	minDistance = int32(math.Min(float64(minDistance), float64(syntheticCurIndex - recentlyIndex)))

	// Update recentlyIndex
	memo[num] = syntheticCurIndex
    }

    if minDistance == lenA {
	// No any pair exist
	return -1
    } else {
	return minDistance
    }
}
