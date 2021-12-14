package main
import ("fmt")

func main() {
    var bill = []int32{3,10,2,9}
    var k, b int32 = 1, 4
    var result int32 = bonAppetit(bill, k, b)
    fmt.Println("result:", result)
}

func bonAppetit(bill []int32, k int32, b int32) int32 {
    /* 
    Explanations:
    k -> The 0-based index of the item that Anna did not eat.
    b -> The amount of money that Brian charged Anna for her shar of the bill
    */
    var CORRECT_SHARE = "Bon Appetit"
    var totalPrice int32 = 0
    lenBill = len(bill)
    for i = 0; i < lenBill; i++ {
	if i == k {
	    continue
	}
	totalPrice += bill[i]
    }

    var result int32
    if totalPrice == b {
	result = CORRECT_SHARE
    } else {
	result = b - totalPrice
    }

    return result
}

