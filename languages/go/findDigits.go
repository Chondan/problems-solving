package main
import ("fmt")

func main() {
    var n int32 = 124
    var ans int32 = findDigits(n)
    fmt.Println("ans:", ans)
}

func findDigits(n int32) int32 {
    var number int32 = n
    var count int32 = 0
    for ; number != 0; number /= 10 {
	var lastDigit int32 = number % 10
	if lastDigit == 0 { continue }

	if n % lastDigit == 0 {
	    count += 1
	}
    }

    return count
}
