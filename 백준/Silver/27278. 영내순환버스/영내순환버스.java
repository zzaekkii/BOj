import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        // 승하차 지점 N, 병사 M명
        StringTokenizer st = new StringTokenizer(br.readLine());
        final int n = Integer.parseInt(st.nextToken());
        final int m = Integer.parseInt(st.nextToken());

        int[] durationPreSum = new int[n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 2; i <= n; i++) {
            durationPreSum[i] = durationPreSum[i - 1] + Integer.parseInt(st.nextToken());
            ;
        }
        final int totalRotateTime = durationPreSum[n] + Integer.parseInt(st.nextToken());
        ;


        int lastTime = 0;
        // 케이스별 가장 늦게 도착하는 시간으로 업데이트
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            final int pickUpPoint = Integer.parseInt(st.nextToken());
            final int dropPoint = Integer.parseInt(st.nextToken());
            final int waitStart = Integer.parseInt(st.nextToken());

            // 기다린 후 버스가 도착한 시간
            int pickUpTime = nextArrival(durationPreSum, pickUpPoint, totalRotateTime, waitStart);

            // 버스 이동 시간
            int duration = timeToDest(durationPreSum, dropPoint, pickUpPoint, totalRotateTime);

            int dropTime = pickUpTime + duration;

            lastTime = Math.max(lastTime, dropTime);
        }

        bw.write(String.valueOf(lastTime));
        bw.flush();
    }

    private static int nextArrival(int[] durationPreSum, int pickUpPoint, int totalRotateTime, int waitStart) {
        int firstArrival = durationPreSum[pickUpPoint];

        // 1. 버스 아직 안 옴
        if (waitStart <= firstArrival) {
            return firstArrival;
        }

        // 2. 이미 버스가 지나간 상황
        int diff = waitStart - firstArrival;
        int rotateCount = (diff + (totalRotateTime - 1)) / totalRotateTime;
        return firstArrival + rotateCount * totalRotateTime;
    }

    private static int timeToDest(int[] durationPreSum, int dropPoint, int pickUpPoint, int totalRotateTime) {
        if (pickUpPoint < dropPoint) {
            return durationPreSum[dropPoint] - durationPreSum[pickUpPoint];
        }
        return (totalRotateTime - durationPreSum[pickUpPoint]) + durationPreSum[dropPoint];
    }
}
