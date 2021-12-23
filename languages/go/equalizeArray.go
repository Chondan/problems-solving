package main
import (
    "fmt"
    "math"
)

func main() {
    var arr = []int32{3,3,2,1,3}
    var ans int32 = equalizeArray(arr)
    fmt.Println("ans:", ans)
}

/* 
Analysis

Find the most occurrence
0. Given map<int, int> freq, mostOccurrence = -1
1. Loop through arr -> freq[arr[i]] += 1 and mostOccurrence = max(freq[arr[i]], mostOccurrence)
2. answer = len(arr) - mostOccurrence

*/
func equalizeArray(arr []int32) int32 {
    var (
	freq = make(map[int32]int32)
	mostOccurrence int32 = -1
	lenArr int32 = int32(len(arr))
    )

    for i := 0; int32(i) < lenArr; i++ {
	freq[arr[i]] += 1
	mostOccurrence = int32(math.Max(float64(mostOccurrence), float64(freq[arr[i]])))
    }

    return lenArr - mostOccurrence
}
