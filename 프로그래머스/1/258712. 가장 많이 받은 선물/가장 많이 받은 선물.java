import java.util.*;

class Solution {
    
    HashMap<String, Integer> nameTag = new HashMap<>(); // 이름별 인덱스.
    int[][] count = new int[51][51]; // A -> B 선물 보낸 횟수.
    int[] giftPoint = new int[51]; // 선물 지수.
    
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        
        // 애들 이름 별로 인덱스 분배.
        int len=friends.length;
        for(int i=0;i<len;i++)
            nameTag.put(friends[i],i);
        
        // 선물 기록 확인.
        for(String history: gifts){
            String tokens[] = history.split(" ");
            
            int fromIdx=nameTag.get(tokens[0]);
            int toIdx=nameTag.get(tokens[1]);
            
            count[fromIdx][toIdx]++;
            
            // 선물 지수 계산.
            giftPoint[fromIdx]++;
            giftPoint[toIdx]--;
        }
        
        // friends 돌아가면서 1:1 확인.
        for(int i=0;i<len;i++){
            int giftCount=0;
            
            for(int j=0;j<len;j++){
                if(i==j || count[i][j] < count[j][i]) continue;
                
                if(count[i][j] > count[j][i]) // a가 더 많이 줌.
                    giftCount++;
                else if(giftPoint[i] > giftPoint[j]) // 교류 없는데, a가 지수 더 높음.
                    giftCount++;
            }
            
            // 최대값 판별.
            if(answer<giftCount)
                answer=giftCount;
        }
        
        return answer;
    }
}