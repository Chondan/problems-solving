package main
import (
    "fmt"
    "math"
)

func main() {
    var (
	widths = []int32{2,3,1,2,3,2,3,3}
	cases = [][]int32{{0,3},{4,6},{6,7},{3,5},{0,7}}
    )
    var ans []int32 = serviceLane(widths, cases)
    fmt.Println("ans:", ans)
}

func getMinInRangeInclusive(arr []int32, start int32, end int32) int32 {
    var minInRange int32 = math.MaxInt32
    for i := start; i <= end; i++ {
	minInRange = int32(math.Min(float64(minInRange), float64(arr[i])))
    }
    return minInRange
}

func serviceLane(widths []int32, cases [][]int32) []int32 {
    var minWidths = []int32{}

    for _, _case := range(cases) {
	var entry, exit int32 = _case[0], _case[1]
	var minWidthFromEntryToExit int32 = getMinInRangeInclusive(widths, entry, exit)
	minWidths = append(minWidths, minWidthFromEntryToExit)
    }

    return minWidths
}
