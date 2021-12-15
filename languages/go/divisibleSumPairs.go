package main
import ("fmt")

func main() {
    var numbers = []int32{1,2,3,4,5,6}
    var k int32 = 5
    var result int32 = divisibleSumPairs(numbers, k)
    fmt.Println("result:", result)
}

func divisibleSumPairs(numbers []int32, k int32) int32 {
    var count int32 = 0
    var numbersLength = len(numbers)
    for i := 0; i < numbersLength - 1; i++ {
	for j := i + 1; j < numbersLength; j++ {
	    var sum int32 = numbers[i] + numbers[j]
	    if sum % k == 0 {
		count += 1
	    }
	}
    }
    return count
}

