import java.io.*;

public class Main {
    private static final int[] PATTERN = {1, 2, 3, 4, 5, 4, 3, 2};
    private static final int PATTERN_COUNT = 8;

    private static final BufferedReader BR = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter BW = new BufferedWriter(new OutputStreamWriter(System.out));
//    private final static StringTokenizer ST;
//    st = new StringTokenizer(BR.readLine());

    public static void main(String[] args) throws Exception {
        int injuredFinger = Integer.parseInt(BR.readLine());
        int count = Integer.parseInt(BR.readLine());

        // 주기당 아픈 손가락 쓰이는 횟수
        int perCycle = (injuredFinger == 1 || injuredFinger == 5) ? 1 : 2;

        // 아픈 손가락 한계까지 쓸 수 있는 주기
        long maxCycle = count / perCycle;

        // 한 주기에 8가지 패턴 존재
        long result = maxCycle * PATTERN_COUNT;

        // 마지막 미완성 사이클 나머지 처리
        int remain = count % perCycle;

        for (int f : PATTERN) {
            if (remain == 0 && f == injuredFinger) break;

            result++;

            if (f == injuredFinger) remain--;
        }


        BW.write(String.valueOf(result));
        BW.flush();
    }
}
