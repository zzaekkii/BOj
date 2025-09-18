import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        Map<String, String> uidToName = new HashMap<>();
        ArrayList<String[]> logs = new ArrayList<>();

        for(String line: record){
            String[] parts = line.split(" ");
            String type = parts[0];
            String uid = parts[1];
            
            if(type.equals("Leave")){
                logs.add(new String[]{type, uid});
            }
            else{
                String nickname = parts[2];
                uidToName.put(uid, nickname);
                
                if(type.equals("Enter")){
                    logs.add(new String[]{type, uid});
                }
            }
        }
        
        int len = logs.size();
        String[] answer = new String[len];
        for(int i=0; i<len; i++){
            String type = logs.get(i)[0];
            String uid = logs.get(i)[1];
            String nickname = uidToName.get(uid);
            
            if(type.equals("Enter")){
                answer[i] = nickname + "님이 들어왔습니다.";
            }
            else{
                answer[i] = nickname + "님이 나갔습니다.";
            }
        }
        
        return answer;
    }
}


/**
    1. uid별 nickname을 해시맵에 저장
    2. Enter 및 Leave 기록 uid와 함께 순서대로 기록
    3. Enter 및 Change에서 uid 별 nickname 변경 시 해시맵에도 반영
    4. 최종적으로 Enter/Leave 기록 출력하며, uid에 맞는 nickname으로 가져오기
**/