class Solution {
    public int solution(String my_string, String is_prefix) {        
        int myLen=my_string.length();
        int preLen=is_prefix.length();
        if(preLen>myLen)return 0;
        
        for(int i=0;i<preLen;i++)
            if(my_string.charAt(i)!=is_prefix.charAt(i)){
                return 0;
            }
        return 1;
    }
}