import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int[] solution(String[] names, int[] yearning, String[][] photos) {
        HashMap<String, Integer> score = new HashMap<>();
        
        int count = names.length;
        for (int i = 0; i < count; i++) {
            score.put(names[i], yearning[i]);
        }
        
        ArrayList<Integer> answer = new ArrayList<>();
        for (String[] photo : photos) {
            int total = 0;
            for (String name : photo) {
                total += score.getOrDefault(name, 0);
            }
            answer.add(total);
        }
        return answer.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}