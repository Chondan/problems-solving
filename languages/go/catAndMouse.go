package main
import (
    "fmt"
    "math"
)

func main() {
    var (
	x int32 = 1
	y int32 = 2
	z int32 = 3
    )
    var result string = catAndMouse(x, y, z)
    fmt.Println("result:", result)
}

func catAndMouse(x int32, y int32, z int32) string {
    var diffA = math.Abs(float64(x - z))
    var diffB = math.Abs(float64(y - z))

    if diffA < diffB {
	return "Cat A"
    } else if diffB < diffA {
	return "Cat B"
    } else {
	return "Mouse C"
    }
}
