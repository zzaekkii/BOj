import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for (String[] cloth : clothes) {
            map.merge(cloth[1], 1, Integer::sum);
        }
        
        int total = 1;
        for (int value : map.values()) {
            total *= value + 1;
        }
        
        return total - 1;
    }
}