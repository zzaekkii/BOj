import java.util.*;

class Solution {
    static final Set<String> WORDS = new HashSet<>(
        Arrays.asList("aya", "ye", "woo", "ma")
    );
    
    public int solution(String[] babbling) {
        int cnt = 0;
        
        for(String word: babbling)
            if(isComposed(word)) cnt++;
        
        return cnt;
    }
    
    public boolean isComposed(String bab){
        if(bab.isEmpty()) return true;
        
        for(String word: WORDS){
            if(bab.startsWith(word)){
                if(isComposed(bab.substring(word.length())))
                    return true;
            }
        }
        
        return false;
    }
}