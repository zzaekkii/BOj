// 정렬 후, 이분탐색 하면 될 듯.
import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        int len=citations.length;
        
        int st=0, en=citations[len-1];
        while(st<=en){
            int md=(st+en)/2;
            
            boolean flag=false;
            for(int i=0;i<len;i++){
                if(citations[i]>=md&&len-i>=md)
                    flag=true;
            }
            
            if(flag){
                answer=Math.max(answer,md);
                st=md+1;
            }
            else en=md-1;
        }
        
        return answer;
    }
}