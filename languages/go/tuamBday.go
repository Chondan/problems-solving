package main
import (
    "fmt"
    "math"
)

func main() {
    var b, w, bc, wc, z int32 = 7, 7, 4, 2, 1
    var ans int64 = tuamBday(b, w, bc, wc, z)
    fmt.Println("ans:", ans)
}

/* 
Analysis

Decide wheter to convert the gift
1. from black to white: 
- if bc > wc + z then convert black to white 
- new price for b = wc + z
2. from white to black:
- if wc > bc + z then convert white to black
- new price for w = bc + z
*/
func tuamBday(b int32, w int32, bc int32, wc int32, z int32) int64 {
    var bPrice int32 = int32(math.Min(float64(bc), float64(wc + z)))
    var wPrice int32 = int32(math.Min(float64(wc), float64(bc + z)))
    var totalPrice int64 = int64(b*bPrice + w*wPrice) 
    return totalPrice
}
