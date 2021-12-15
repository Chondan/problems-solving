package main
import (
    "fmt"
    "sort"
    "math"
)

func main() {
    var a = []int32{1,1,2,2,4,4,5,5,5}
    var result int32 = pickingNumbers(a)
    fmt.Println("result:", result)
}

func pickingNumbers(a []int32) int32 {
    sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })

    var (
	startOfSubArray int32 = a[0]
	globalCount int32 = 1
	count int32 = 1
    )
    for i := 1; i < len(a); i++ {
	var num int32 = a[i]
	if num - startOfSubArray <= 1 {
	    count += 1
	} else {
	    startOfSubArray = num
	    globalCount = int32(math.Max(float64(globalCount), float64(count)))
	    count = 1
	}
	globalCount = int32(math.Max(float64(globalCount), float64(count)))
    }

    return globalCount
}
