package main
import ("fmt")

func main() {
    var s string = "aba"
    var n int64 = 10
    var ans int64 = repeatedString(s, n)
    fmt.Println("ans:", ans)
}

/* 
Analysis

Given: s = "aba", n = 10
#repeat = floor(10 / len(s)), remaining = 10 % len(s) 

Count letter 'a':
0. Given count = 0, extra = 0
1. Loop through string: 
    - if char == 'a' then count += 1
    - if char == 'a' and index < remaining then count += 1 and extra += 1
2. answer = (count * #repeat) + extra

*/
func repeatedString(s string, n int64) int64 {
    const charToCount byte = 'a'
    var (
	lenS int64 = int64(len(s))
	numberOfRepeat int64 = n / lenS
	remaining int64 = n % lenS
	count int64 = 0
	extra int64 = 0
    )

    for i := 0; int64(i) < lenS; i++ {
	if s[i] == charToCount {
	    count += 1

	    if int64(i) < remaining {
		extra += 1
	    }
	}
    }

    return (count * numberOfRepeat) + extra
}
