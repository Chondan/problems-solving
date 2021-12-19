package main
import (
    "fmt"
    "math"
)

func main() {
    var arr = []int32{1,3,5,7,9}
    miniMaxSum(arr)
}

func miniMaxSum(arr []int32) {
    var (
        totalSum int64 = 0
        minSum int64 = math.MaxInt64
        maxSum int64 = math.MinInt64
    )
   // Find total sum            
   for _, value := range(arr) {
       totalSum += int64(value)
   }

   // Subtract current visited number from the totalSum to find minSum and maxSum
   for _, value := range(arr) {
       var fourSum int64 = totalSum - int64(value)
       minSum = int64(math.Min(float64(minSum), float64(fourSum)))
       maxSum = int64(math.Max(float64(maxSum), float64(fourSum)))
   }

   fmt.Println(minSum, maxSum)
}
