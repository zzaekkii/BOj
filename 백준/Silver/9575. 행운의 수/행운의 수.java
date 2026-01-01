import java.io.*;
import java.util.*;

public class Main {

    private static final int[] LUCKY_NUMBERS = {5, 8};

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        final int t = readInteger();

        for (int test = 0; test < t; test++) {
            // 수열 A 읽기
            final int aLen = readInteger();
            final List<Integer> arrA = fillElements(aLen);

            // 수열 B 읽기
            final int bLen = readInteger();
            final List<Integer> arrB = fillElements(bLen);

            // 수열 C 읽기
            final int cLen = readInteger();
            final List<Integer> arrC = fillElements(cLen);


            // 만든 행운의 수 저장
            Set<Integer> madeNumbers = new HashSet<>();

            for (int a : arrA) {
                for (int b : arrB) {
                    for (int c : arrC) {
                        final int sum = a + b + c;

                        if (isLuckyNumber(sum)) {
                            madeNumbers.add(sum);
                        }
                    }
                }
            }

            // 서로 다른 행운의 수 출력
            bw.write(madeNumbers.size() + "\n");
            bw.flush();
        }
    }

    private static boolean isLuckyNumber(int num) {
        while (num > 0) {
            final int target = num % 10;
            num /= 10;

            boolean checked = false;
            for (int luckyNumber : LUCKY_NUMBERS) {
                if (luckyNumber == target) {
                    checked = true;
                    break;
                }
            }

            if (!checked) {
                return false;
            }
        }

        return true;
    }

    private static int readInteger() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private static List<Integer> fillElements(int len) throws IOException {
        List<Integer> arr = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < len; i++) {
            arr.add(Integer.parseInt(st.nextToken()));
        }
        return arr;
    }
}
