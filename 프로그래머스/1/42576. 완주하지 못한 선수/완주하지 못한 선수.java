import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String c : completion) {
            map.merge(c, 1, Integer::sum);
        }
        
        for (String p : participant) {
            if (map.get(p) == null || map.get(p) <= 0) {
                return p;
            }
            map.merge(p, -1, Integer::sum); 
        }
        
        return null;
    }
}