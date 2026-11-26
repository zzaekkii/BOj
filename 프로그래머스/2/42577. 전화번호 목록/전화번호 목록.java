import java.util.*;
import java.io.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book, Collections.reverseOrder());
        HashSet<String> set = new HashSet<>();
        
        for (String phone : phone_book) {
            if (set.contains(phone)) {
                return false;
            }
            
            StringBuilder sb = new StringBuilder();
            for (char c : phone.toCharArray()) {
                sb.append(c);
                
                set.add(sb.toString());
            }
        }
        
        return true;
    }
}