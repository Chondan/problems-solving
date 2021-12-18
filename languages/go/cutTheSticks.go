package main
import (
    "fmt"
    "sort"
)

func main() {
    var arr = []int32{1,2,3,4,3,3,2,1}
    var ans = cutTheSticks(arr)
    fmt.Println("ans:", ans)
}

func cutTheSticks(arr []int32) []int32 {
    var (
	lenArr int32 = int32(len(arr))
	sortedSticks []int32 = arr
	countMinimum int32 = 1
	curCutSticks int32 = lenArr
	countSticks = []int32{curCutSticks}
    )

    // Sort arr
    sort.Slice(sortedSticks, func(i, j int) bool { return sortedSticks[i] < sortedSticks[j] })

    for i := 1; int32(i) < lenArr; i++ {
	if arr[i - 1] == arr[i] {
	    countMinimum += 1
	} else {
	    // Update countSticks
	    curCutSticks -= countMinimum
	    countSticks = append(countSticks, curCutSticks)
	    countMinimum = 1
	}
    }

    return countSticks
}
/* 
arr = {1,2,3,4,3,3,2,1}
sortedArr = {1,1,2,2,3,3,3,4}

countSticks = {8}
count minimum -> 2
countSticks = {8,8-2} = {8, 6}
count minimum -> 2
countSticks = {8,6,6-2} = {8,6,4}
count minimum -> 3
countSticks = {8,6,4,4-3} = {8,6,4,1}

stop if curSticks == 1
*/
