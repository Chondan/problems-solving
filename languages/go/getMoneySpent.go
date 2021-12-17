package main
import (
    "fmt"
    "math"
)

func main() {
    var (
	keyboards = []int32{3,1,8}
	drives = []int32{5,2,1,2,3,4,5,6}
	b int32 = 10
    )
    var ans int32 = getMoneySpent(keyboards, drives, b)
    fmt.Println("ans:", ans)
}

func getMoneySpent(keyboards []int32, drives []int32, b int32) int32 {
    var moneySpent int32 = -1
    for i := 0; i < len(keyboards); i++ {
	for j := 0; j < len(drives); j++ {
	    var cost int32 = keyboards[i] + drives[j]
	    if cost > b { continue }
	    moneySpent = int32(math.Max(float64(moneySpent), float64(cost)))
	}
    }

    return moneySpent
}
