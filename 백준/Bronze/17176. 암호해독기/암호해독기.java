// package boj.no17176_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws IOException {
        int cryptoLength = inputView.readCryptoLength();
        List<Integer> cryptoNumbers = inputView.readCryptoNumbers(cryptoLength);
        String plainText = inputView.readPlainText(cryptoLength);
        outputView.printResult(Decoder.canMakeText(cryptoNumbers, plainText));
    }

    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public int readCryptoLength() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        public List<Integer> readCryptoNumbers(int cryptoLength) throws IOException {
            StringTokenizer tokens = new StringTokenizer(br.readLine());

            List<Integer> cryptos = new ArrayList<>();
            while (tokens.hasMoreTokens()) {
                try {
                    cryptos.add(Integer.parseInt(tokens.nextToken()));
                } catch (NumberFormatException e) {
                    throw new IllegalArgumentException("암호는 숫자로만 주어져야 합니다.");
                }
            }

            if (cryptos.size() != cryptoLength) {
                throw new IllegalArgumentException("주어진 길이와 실제 암호의 길이가 맞지 않습니다.");
            }

            return cryptos;
        }

        public String readPlainText(int cryptoLength) throws IOException {
            String input = br.readLine();

            if (input.length() != cryptoLength) {
                throw new IllegalArgumentException("암호의 길이와 평문의 길이가 다릅니다.");
            }

            return input;
        }
    }

    static final class Decoder {

        public static boolean canMakeText(List<Integer> cryptos, String plainText) {
            char[] decodedText = decode(cryptos).toCharArray();
            Arrays.sort(decodedText);

            char[] plainTextToChar = plainText.toCharArray();
            Arrays.sort(plainTextToChar);

            return Arrays.equals(decodedText, plainTextToChar);
        }

        private static String decode(List<Integer> cryptos) {
            StringBuilder result = new StringBuilder();
            for (int crypto : cryptos) {
                result.append(translateAsciiToChar(crypto));
            }

            return result.toString();
        }

        private static char translateAsciiToChar(int value) {
            for (CryptoPatten crypto : CryptoPatten.values()) {
                if (crypto.MINIMUM_BOUND <= value && value <= crypto.MAXIMUM_BOUND) {
                    return (char) ((int) crypto.START_VALUE + (value - crypto.MINIMUM_BOUND));
                }
            }
            throw new IllegalArgumentException("해독할 수 없는 암호입니다.");
        }

    }

    enum CryptoPatten {
        BLANK(0, 0, ' '),
        UPPER(1, 26, 'A'),
        LOWER(27, 52, 'a');

        private final int MINIMUM_BOUND;
        private final int MAXIMUM_BOUND;
        private final char START_VALUE;

        CryptoPatten(int minimumBound, int maximumBound, char startValue) {
            MINIMUM_BOUND = minimumBound;
            MAXIMUM_BOUND = maximumBound;
            START_VALUE = startValue;
        }
    }

    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(boolean isSameText) {
            String answer = "n";
            if (isSameText) {
                answer = "y";
            }
            System.out.println(answer);
        }
    }
}
