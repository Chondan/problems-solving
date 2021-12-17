package main
import (
    "fmt"
    "math"
)

func main() {
    var (
	h = []int32{1,3,1,3,1,4,1,3,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}
	word string = "abc"
    )
    var ans int32 = designerPdfViewer(h, word)
    fmt.Println("ans:", ans)
}

func designerPdfViewer(h []int32, word string) int32 {
    var (
	a rune = 'a'
	aAscii int = int(a)
	heightOfTallestChar int32
    )

    for _, char := range(word) {
	var ascii = int(char)
	var hIndex = ascii - aAscii
	heightOfTallestChar = int32(math.Max(float64(heightOfTallestChar), float64(h[hIndex])))
    }

    return int32(len(word)) * heightOfTallestChar
}
