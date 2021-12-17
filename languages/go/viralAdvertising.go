package main
import (
    "fmt"
    "math"
)

func main() {
    var n int32 = 5
    var ans int32 = viralAdvertising(n)
    fmt.Println("ans:", ans)
}

func viralAdvertising(n int32) int32 {
    var (
	share int32 = 5
	like int32 = 2
	cumulativeLikes int32 = 2
	i int32 = 2
    )

    for ; i <= n; i++ {
	share = like * 3
	like = int32(math.Floor(float64(share / 2)))
	cumulativeLikes += like 
    }

    return cumulativeLikes
}
