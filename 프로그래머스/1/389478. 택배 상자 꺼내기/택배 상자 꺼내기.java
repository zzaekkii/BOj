// 자바 ps 첫 시작.
// 단순하지 않게 풀 거임.
// 이 문제는 사실 배열에 넣으면 그냥 끝이긴 하나,
// 범위가 매우 커지더라도 메모리 & 시간 걱정 제로.
class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        
        // 몇 계층(0.x~1.0)이냐 (계층에 따라 덧셈 규칙이 나뉨)
        // 홀 짝 결과로 뽑을 것 (짝홀짝홀)
        int level = num / w;
        
        // 나눠떨어지는 값은 -1 처리해야 층이 같아짐.
        if (num % w == 0) level--;
        
        int ori_level = level % 2;
        
        // 계층별 덧셈 규칙값.
        int tmp = (num + (w - 1)) - ((num + (w - 1)) % w);
        int gap = (tmp - num) * 2 + 1;
        
        // 최종 계산.
        for (; num <= n; level++, answer++){
            if (level % 2 == ori_level) num += gap;
            else num += (w * 2) - gap;
        }

        return answer;
    }
}