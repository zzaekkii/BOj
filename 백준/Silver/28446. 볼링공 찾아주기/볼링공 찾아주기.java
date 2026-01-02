import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        final int requestCnt = readInteger();

        Map<Integer, Integer> lockers = new HashMap<>();

        for (int request = 0; request < requestCnt; request++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            final int operator = Integer.parseInt(st.nextToken());

            switch (operator) {
                case 1:
                    final int lockerNum = Integer.parseInt(st.nextToken());
                    final int ballWeight = Integer.parseInt(st.nextToken());

                    lockers.put(ballWeight, lockerNum);
                    break;
                case 2:
                    final int requiredWeight = Integer.parseInt(st.nextToken());

                    bw.write(lockers.get(requiredWeight) + "\n");
                    break;
                default:
                    break;
            }
        }

        bw.flush();
    }

    private static int readInteger() throws IOException {
        return Integer.parseInt(br.readLine());
    }
}
