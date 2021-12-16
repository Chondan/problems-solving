package main
import ("fmt")

func main() {
    var n int32 = 5
    var ans int32 = utopianTree(n)
    fmt.Println("ans:", ans)
}

func utopianTree(n int32) int32 {
    /* 
    n = 0 -> 1
    n = 1 -> 2 * f(0) -> 2
    n = 2 -> 1 + f(1) -> 1 + (2 * f(0)) -> 3
    */
    if n == 0 {
	return 1
    }

    if n % 2 == 0 {
	return 1 + utopianTree(n - 1)
    } else {
	return 2 * utopianTree(n - 1)
    }
}

