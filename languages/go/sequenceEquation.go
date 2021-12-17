package main
import ("fmt")

func main() {
    var p = []int32{5,2,1,3,4}
    var ans []int32 = permutationEquation(p)
    fmt.Println("ans:", ans)
}

func permutationEquation(p []int32) []int32 {
    var result = []int32{}

    // Get num to pos (pos will start at 1) hashmap
    var numToPos = make(map[int32]int32)
    for index, value := range(p) {
	numToPos[value] = int32(index) + 1
    }

    for x := 1; x <= len(p); x++ {
	// Find any integer y such that p(p(y)) = y
	var y int32 = numToPos[numToPos[int32(x)]]
	result = append(result, y)
    }

    return result
}
