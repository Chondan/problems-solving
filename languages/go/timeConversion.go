package main
import (
    "fmt"
    "strconv"
)

func main() {
    var s string = "06:40:03AM"
    var ans string = timeConversion(s)
    fmt.Println("ans:", ans)
}

/* 
Analysis

The given string is always in the format of
> "HH:MM:SSXX" (XX can be AM or PM)

To convert into the 24-hour clock format:
1. Check AM/PM -> Look at index 8 of string -> string[8]
2. if string[8] == A -> do nothing but if HH = 12 change it to 12 - 12 (00)
3. if string[8] == P -> HH += 12 but if HH = 12 do nothing
*/
func timeConversion(s string) string {
    var (
	indexToCheckAMFormat int32 = 8
	isInAMFormat bool
	hhStr string = string(s[0]) + string(s[1])
	hhNum int
	newHHStr string = hhStr
    )
    isInAMFormat = s[indexToCheckAMFormat] == 'A'
    hhNum, _ = strconv.Atoi(hhStr)

    if isInAMFormat {
	if hhNum == 12 {
	    newHHStr = "00"
	}
    } else {
	if hhNum != 12 {
	    newHHStr = strconv.Itoa(hhNum + 12)
	}
    }

    fmt.Println(newHHStr)
    return newHHStr + s[2:8]
}
