package languages.java;

import java.util.HashMap;

public class BowlingPins {
    private static String[] pins = new String[]{
        "I I I I",
        " I I I ",
        "  I I  ",
        "   I   "
    };

    private static int getPinRowIndex(int pinNum) {
        if (pinNum >= 7) return 0;
        else if (pinNum >= 4) return 1;
        else if (pinNum >= 2) return 2;
        else if (pinNum == 1) return 3;
        else return -1;
    }

    private static int getPinPosInRow(int pinRowIndex, int pinNum) {
        HashMap<Integer, Integer> startNumOfRowMap = new HashMap<>();
        startNumOfRowMap.put(0, 7);
        startNumOfRowMap.put(1, 4);
        startNumOfRowMap.put(2, 2);
        startNumOfRowMap.put(3, 1);
        
        int startPosOfRow = pinRowIndex;
        int startNumOfRow = startNumOfRowMap.get(pinRowIndex);
        int pinPosInRow = startPosOfRow + ((pinNum - startNumOfRow) * 2);
        return pinPosInRow;
    }

    private static String bowlingPins(int[] arr) {
        for (int pinNum: arr) {
            if (pinNum < 1 || pinNum > 10) continue; 
            
            // Get row of current pin
            int pinRowIndex = getPinRowIndex(pinNum);
            if (pinRowIndex == -1) continue;

            // Get position in the row of current pin
            int pinPosInRow = getPinPosInRow(pinRowIndex, pinNum);
            String pinRow = pins[pinRowIndex];
            String[] pinRowArr = pinRow.split("");

            // Replace value of the position with whitespace
            pinRowArr[pinPosInRow] = " ";
            pins[pinRowIndex] = String.join("", pinRowArr);
        }
        
        return String.join("\n", pins);
    }
    
    public static void main(String[] args) {
        int[] testArray = new int[]{3, 5, 9};
        String ans = bowlingPins(testArray);
        System.out.println("ans:");
        System.out.println(ans);
    }
}