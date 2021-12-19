package main
import ("fmt")

func main() {
    var c = []int32{0,0,1,0,0,1,0}
    var ans int32 = jumpingOnClouds(c)
    fmt.Println("ans:", ans)
}

/* 
- The player can jump on any cumulus cloud having a number that is equal
to the number of the current cloud plus 1 or 2.
- The player must avoid the thunderheads.

Analysis -> clouds = {0,0,1,0,0,1,0}

starting from index 0: 2 choices to jump -> 1 step or 2 steps
- select the furthest -> go 2 steps if clouds[curIndex + 2] != 1 otherwise go 1

*/
func jumpingOnClouds(c []int32) int32 {
    const THUNDERHEADS int32 = 1
    var (
	countJump int32 = 0
	curIndex int32 = 0
	clouds []int32 = c
    )

    for ; curIndex != int32(len(clouds)) - 1; {
	var isOutOfIndex bool = curIndex + 2 >= int32(len(clouds))
	var canGoTwoSteps bool = !isOutOfIndex && clouds[curIndex + 2] != THUNDERHEADS;
	if canGoTwoSteps {
	    curIndex += 2
	} else {
	    curIndex += 1
	}
	countJump += 1
    }

    return countJump
}
