package main
import ("fmt")

func main() {
    var (
	c = []int32{0,0,1,0,0,1,1,0}
	k int32 = 2
    )
    var ans int32 = jumpingOnClouds(c, k)
    fmt.Println("ans:", ans)
}

func isThundercloud(cloudNumber int32) bool {
    return cloudNumber == 1
}

func getRemainingEnergy(c []int32, jumpIndex int32, energy int32) int32 {
    if isThundercloud(c[jumpIndex]) {
	return energy - 3
    } else {
	return energy - 1
    }
}

func jumpingOnClouds(c []int32, k int32) int32 {
    var (
	energy int32 = 100
	jumpIndex int32 = 0
	lenCloud int32 = int32(len(c))
    )

    // First jump
    energy = getRemainingEnergy(c, jumpIndex, energy)
    jumpIndex = (jumpIndex + k) % lenCloud

    for ; jumpIndex % lenCloud != 0; {
	energy = getRemainingEnergy(c, jumpIndex, energy)
	jumpIndex = (jumpIndex + k) % lenCloud
    }

    return energy
}
