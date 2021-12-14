package main
import ("fmt")

func main() {
    var steps int32 = 8
    var path string = "UDDDUDUU"
    var result int32 = countingValleys(steps, path)
    fmt.Println("result:", result)
}

func countingValleys(steps int32, path string) int32 {
    /* 
    -- Explanations --
    - Hikes always start and end at sea level.
    - A valley is a sequence of consecutive steps below sea level, 
    starting with a step down from sea level and ending with a step 
    up to sea level.
    */
    var (
	level int32 = 0
	i int32 = 0
	stepToNum = map[string]int32{"U": 1, "D": -1}
	valley int32 = 0
	isInValley bool = false
    )
    for ; i < steps; i++ {
	stringIndex := int(i)
	step := string(path[stringIndex])
	level += stepToNum[step]

	// Stepping down to the valley
	if level == -1 {
	    isInValley = true
	}

	// Stepping up from the valley
	if level == 0 && isInValley {
	    valley += 1
	    isInValley = false
	}
    }

    return valley
}
