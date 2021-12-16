package main
import ("fmt")

func main() {
    var (
	k int32 = 3
	a = []int32{-1,-3,4,2}
    )
    var ans string = angryProfessor(k, a)
    fmt.Println("ans:", ans)
}

func isArriveOnTime(arrivalTime int32) bool {
    return arrivalTime <= 0
}

func angryProfessor(k int32, a []int32) string {
    var numberOfStudentArriveOnTime int32 = 0

    for _, arrivalTime := range(a) {
	if isArriveOnTime(arrivalTime) {
	    numberOfStudentArriveOnTime += 1
	}
    }

    var shouldCancelClass bool = numberOfStudentArriveOnTime < k
    if shouldCancelClass {
	return "YES"
    } else {
	return "NO"
    }
}
