package main
import (
    "fmt"
    "math"
)

func main() {
    var (
	k int32 = 4
	height = []int32{1,6,3,5,2}
    )
    var ans int32 = hurdleRace(k, height)
    fmt.Println("ans:", ans)
}

func hurdleRace(k int32, height []int32) int32 {
    // Find the tallest bar
    var tallest int32 = -1
    for _, value := range height {
	tallest = int32(math.Max(float64(tallest), float64(value)))
    }

    if k < tallest {
	return tallest - k 
    } else {
	return 0
    }
}
