import java.util.*;

class Solution {
    public int solution(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        
        int len = nums.length;
        int count = set.size();
        
        if (count >= len / 2) {
            return len / 2;
        }
        else {
            return count;
        }
    }
}