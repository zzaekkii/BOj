import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        int pivot = toIntDate(today);
        
        // 각 종류별 기간.
        Map<Character, Integer> term = new HashMap<>();
        for(String line: terms){
            String[] parts = line.split(" ");
            term.put(parts[0].charAt(0), Integer.parseInt(parts[1]));
        }
        
        
        // 각 유효기간 max.
        List<Integer> result = new ArrayList<>();
        int len = privacies.length;
        for(int i=0; i<len; i++){
            String[] parts = privacies[i].split(" ");
            int date = toIntDate(parts[0]);
            char type = parts[1].charAt(0);
            int months = term.get(type);
            
            int expire = calculateDate(date, months);
            
            if(expire < pivot)
                result.add(i+1);
        }
        
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private int toIntDate(String date){
        String[] a = date.split("\\.");
        int y = Integer.parseInt(a[0]);
        int m = Integer.parseInt(a[1]);
        int d = Integer.parseInt(a[2]);
        
        // YYYYMMDD
        return y*10000 + m*100 + d;
    }
    
    private int calculateDate(int yyyymmdd, int months){
        int y = yyyymmdd / 10000;
        int m = (yyyymmdd % 10000) / 100;
        int d = yyyymmdd % 100;
        
        m += months;
        y += (m-1) / 12;
        m = (m-1) % 12 + 1;
        
        // 1일이면 이전 달로 넘어간다.
        if(d == 1){
            // 1월이면 이전 해로 넘어간다.
            if(m == 1){
                y--;
                m=12;
            }
            else{
                m--;
            }            
            d=28;
        }
        else d-=1;
        
        return y*10000 + m*100 + d;
    }
}

/**
    1. privacies 데이터를 바로 유효기간 max만큼 계산 후 저장
        1.5. 저장 시, int형으로 20220519형식으로 저장
    2. 순서대로 넘는지 판별 후, 결과 저장
**/