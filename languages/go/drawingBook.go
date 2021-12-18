package main
import (
    "fmt"
    "math"
)

func main() {
    var n, p int32 = 6, 2
    var ans int32 = pageCount(n, p)
    fmt.Println("ans:", ans)
}

/*
Drawing Book
- page 1 is always on the right side.
- Each page excepts the last page will always be printed on both sides.
- The last page may only be printed on the front.
- They always turn pages one at a time. They can start at the beginning or 
the end of the book.

Analysis
1. Starting from the beginning -> starting page = 1
#visited page = startingPage + 2*(turn)
#turn = ceil((pageNumber - startingPage) / 2)

2. Starting from the end
starting page depend on total pages of the book
pages % 2 == 0 -> starting page = 1
pages %2 != 0 -> starting page = 2

think in the same concept of starting from the beginning
pageNumberFromEnd (starting from the end) = total pages - actual page number + 1
e.g. total pages = 5, actual page = 1, pageNumberFromEnd = 5 - 1 + 1 = 5

To decide the direction to turn the page
e.g. n = 100, page = 50
begining: #turn = ceil((50 - 1) / 2) = 25
end: #turn = ceil((51 - 1) / 2) = 25

e.g. n = 101, page = 50
begining: #turn = ceil((50 - 1) / 2) = 25
end: #turn = ceil((52 - 2) / 2) = 25
*/
func pageCount(n int32, p int32) int32 {
    // Decide turning direction
    var startingPages, pageNumber float32
    var pageNumberFromBeginning, pageNumberFromEnding int32 = p, n - p + 1
    if pageNumberFromBeginning < pageNumberFromEnding {
	// Starting from the beginning
	startingPages = 1
	pageNumber = float32(pageNumberFromBeginning)
    } else {
	// Starting from the end
	if n % 2 == 0 {
	    startingPages = 1
	} else {
	    startingPages = 2
	}
	pageNumber = float32(pageNumberFromEnding)
    }

    var numberOfTurn int32 = int32(math.Ceil(float64((pageNumber - startingPages) / 2)))
    return numberOfTurn
}
