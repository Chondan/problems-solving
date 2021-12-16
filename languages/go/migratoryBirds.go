package main
import (
    "fmt"
    "math"
)

func main() {
    var arr = []int32{1,1,2,2,3}
    var ans int32 = migratoryBirds(arr)
    fmt.Println("ans:", ans)
}

func migratoryBirds(arr []int32) int32 {
    var (
	freq = make(map[int32]int32)
	invertFreq = make(map[int32]int32)
	maxPresent int32 = 0
    )

    for _, birdId := range(arr) {
	freq[birdId] += 1
	var freqOfThisBirdId = freq[birdId]

	if invertFreq[freqOfThisBirdId] == 0 {
	    invertFreq[freqOfThisBirdId] = birdId
	} else {
	    invertFreq[freqOfThisBirdId] = int32(math.Min(float64(birdId), float64(invertFreq[freqOfThisBirdId])))
	}

	maxPresent = int32(math.Max(float64(freqOfThisBirdId), float64(maxPresent)))
    }

    return invertFreq[maxPresent]
}
