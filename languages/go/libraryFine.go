package main
import (
    "fmt"
    "math"
)

func main() {
    var d1, m1, y1 int32 = 14, 7, 2018
    var d2, m2, y2 int32 = 5, 7, 2018
    var ans int32 = libraryFine(d1, m1, y1, d2, m2, y2)
    fmt.Println("ans:", ans)
}

/* 
d1,m1,y1 -> returned date
d2,m2,y2 -> due date
Note: Charges are based only on the least precise measure of lateness.
For example, whether a book is due January 1, 2017 or December 31, 2017, 
if it is returned January 1, 2018, that is a year late.

Analysis

months late = ((12 - m1) + m2) * (y2 - y1)
e.g. 14/03/2018 -> 14/02/2019: months late = (11 * 1) = 11 months late



*/
func getMonthsLateFine(monthsLate int32) int32 { return 500 * monthsLate }
func getDaysLateFine(daysLate int32) int32 { return 15 * daysLate }
func getYearsLateFine() int32 { return 10000 }

func libraryFine(d1 int32, m1 int32, y1 int32, d2 int32, m2 int32, y2 int32) int32 {
    if y1 > y2 {
	return getYearsLateFine()
    } else if y1 == y2 {
	// Month late
	if m1 == m2 {
	    var daysLate int32 = int32(math.Max(float64(d1 - d2), 0))
	    return getDaysLateFine(daysLate)
	} else if m1 > m2 {
	    var monthsLate int32 = m1 - m2
	    return getMonthsLateFine(monthsLate)
	}
    }
    return 0
}

