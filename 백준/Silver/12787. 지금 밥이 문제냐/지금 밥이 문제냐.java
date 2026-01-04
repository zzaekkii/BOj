// package boj.no12787_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws Exception {
        final int testCount = inputView.readTestCount();

        for (int test = 0; test < testCount; test++) {
            TranslateRequest request = inputView.readTranslateRequest();
            TranslateResult result = request.translate();
            outputView.printResult(result);
        }

    }


    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public int readTestCount() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        public TranslateRequest readTranslateRequest() throws IOException {
            StringTokenizer st = new StringTokenizer(br.readLine());

            TranslateType type = TranslateType.fromInt(Integer.parseInt(st.nextToken()));

            String value = st.nextToken();

            return new TranslateRequest(type, value);
        }
    }


    enum TranslateType {
        IPV8_TO_INTEGER(1, new IpV8ToIntegerTranslator()),
        INTEGER_TO_IPV8(2, new IntegerToIpV8Translator());

        private final int value;
        private final Translator translator;

        TranslateType(int value, Translator translator) {
            this.value = value;
            this.translator = translator;
        }

        public static TranslateType fromInt(int value) {
            for (TranslateType type : TranslateType.values()) {
                if (type.value == value) {
                    return type;
                }
            }
            throw new IllegalArgumentException();
        }

        public TranslateResult translate(String value) {
            return translator.translate(value);
        }
    }

    static final class TranslateRequest {

        private final TranslateType type;
        private final String value;

        public TranslateRequest(TranslateType type, String value) {
            this.type = type;
            this.value = value;
        }

        public TranslateResult translate() {
            return type.translate(value);
        }
    }

    /**
     * 변환기
     */
    interface Translator {
        TranslateResult translate(String value);
    }

    static final class IpV8ToIntegerTranslator implements Translator {

        private static final String SEPARATOR = "\\.";

        @Override
        public TranslateResult translate(String value) {
            String[] parts = value.split(SEPARATOR);
            BigInteger result = BigInteger.ZERO;

            for (String part : parts) {
                result = result.shiftLeft(8)
                        .add(BigInteger.valueOf(Integer.parseInt(part)));
            }

            return new IntegerResult(result);
        }
    }

    static final class IntegerToIpV8Translator implements Translator {

        @Override
        public TranslateResult translate(String value) {
            BigInteger num = new BigInteger(value);
            int[] parts = new int[8];

            for (int i = 7; i >= 0; i--) {
                parts[i] = num.and(BigInteger.valueOf(0xFF)).intValue();
                num = num.shiftRight(8);
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 8; i++) {
                if (0 < i) {
                    sb.append(".");
                }
                sb.append(parts[i]);
            }

            return new IpV8Result(sb.toString());
        }
    }

    /**
     * 변환 결과
     */
    interface TranslateResult {
        String getResultAsString();
    }

    static final class IntegerResult implements TranslateResult {

        private final BigInteger result;

        public IntegerResult(BigInteger result) {
            this.result = result;
        }

        @Override
        public String getResultAsString() {
            return String.valueOf(result);
        }
    }

    static final class IpV8Result implements TranslateResult {

        private final String address;

        IpV8Result(String address) {
            this.address = address;
        }

        @Override
        public String getResultAsString() {
            return address;
        }
    }


    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(TranslateResult result) throws IOException {
            bw.write(result.getResultAsString() + "\n");
            bw.flush();
        }
    }
}
