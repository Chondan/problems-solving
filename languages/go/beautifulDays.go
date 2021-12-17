package main
import (
    "fmt"
    "strconv"
    "math"
)

func main() {
    var i, j, k int32 = 20, 23, 6
    var ans int32 = beautifulDays(i, j, k)
    fmt.Println("ans:", ans)
}

func getReversedNumber(number int32) int32 {
    /* 
    -- Reverse --
    example: 120 -> 21
    1*10^0 + 2*10^1 + 0*10^2 
    */
    var numberStr string = strconv.FormatInt(int64(number), 10)
    var reversedNumber int32
    for i := 0; i < len(numberStr); i++ {
	var number, _ = strconv.Atoi(string(numberStr[i]))
	var valueToAdd int32 = int32(math.Pow(float64(10), float64(i))) * int32(number)
	reversedNumber += valueToAdd
    }

    return reversedNumber
}

func isBeautifulDay(day int32, k int32) bool {
    var absDiff int32 = int32(math.Abs(float64(day - getReversedNumber(day))))
    return absDiff % k == 0
}

func beautifulDays(i int32, j int32, k int32) int32 {
    var count int32
    for day := i; day <= j; day++ {
	if isBeautifulDay(day, k) {
	    count += 1
	}
    }

    return count
}
