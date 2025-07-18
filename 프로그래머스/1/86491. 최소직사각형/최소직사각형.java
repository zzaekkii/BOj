class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int maxWidth=0, maxLength=0;
        
        int len=sizes.length;
        for(int i=0;i<len;i++){
            if(sizes[i][0]>sizes[i][1]){
                int tmp=sizes[i][0];
                sizes[i][0]=sizes[i][1];
                sizes[i][1]=tmp;
            }
            
            if(maxWidth<sizes[i][0])maxWidth=sizes[i][0];
            if(maxLength<sizes[i][1])maxLength=sizes[i][1];
        }
        
        answer=maxWidth*maxLength;
        
        return answer;
        
    }
}