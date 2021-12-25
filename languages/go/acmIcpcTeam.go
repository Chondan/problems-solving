package main
import ("fmt")

func main() {
    var topic = []string{"10101", "11110", "00010"}
    var ans []int32 = acmTeam(topic)
    fmt.Println("ans:", ans)
}

func isKnownSubject(subject byte) bool {
    if subject == '1' { return true }
    return false
}

func acmTeam(topic []string) []int32 {
    var result = []int32{0, 0} // [maximum topics, #team that know that many topics]
    var lenTopics = len(topic)
    var lenTopic = len(topic[0])

    for i := 0; i < lenTopics; i++ {
	for j := i + 1; j < lenTopics; j++ {

	    var countKnownTopic int32 = 0
	    var topic1, topic2 string = topic[i], topic[j]
	    for k := 0; k < lenTopic; k++ {
		if isKnownSubject(topic1[k]) || isKnownSubject(topic2[k]) {
		    countKnownTopic += 1
		}
	    }

	    // Update result
	    if countKnownTopic > result[0] {
		result[0] = countKnownTopic
		result[1] = 1
	    } else if countKnownTopic == result[0] {
		result[1] += 1
	    }
	}
    }

    return result
}
