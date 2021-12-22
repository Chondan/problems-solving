package main
import ("fmt")

func main() {
    var n int32 = 25
    extraLongFactorials(n)
}

/* 
Analysis

Given -> array = [1]
i = 2: array = [2]
i = 3: array = [6]
i = 4: 
array = [24]
array = [24, 0] 
array = [4, 2]

i = 5: 
array = [20, 10]
array = [0, 12]
array = [0, 12, 0] -> [0, 2, 1]
*/
func extraLongFactorials(n int32) {
    var digits = []int32{1}
    for i := 2; int32(i) <= n; i++ {
	var lenDigits = len(digits)
	var digitsIndex = 0
	for ; digitsIndex < lenDigits; digitsIndex++ {
	    digits[digitsIndex] *= int32(i);
	}

	for digitsIndex = 0; digitsIndex < lenDigits; digitsIndex++ {
	    if digits[digitsIndex] < 10 { continue }
	    if digitsIndex == lenDigits - 1 { digits = append(digits, 0) }
	    digits[digitsIndex + 1] += digits[digitsIndex] / 10
	    digits[digitsIndex] %= 10
	}

	// Adjust the last element of array to a single digits to prevent big int
	for digitsIndex = len(digits) - 1; digits[digitsIndex] >= 10; {
	    digits = append(digits, 0)
	    digits[digitsIndex + 1] += digits[digitsIndex] / 10
	    digits[digitsIndex] %= 10
	}
    }

    // Output
    fmt.Println("digits:", digits)
    for i := len(digits) - 1; i >= 0; i-- {
	fmt.Print(digits[i])
    }
}

