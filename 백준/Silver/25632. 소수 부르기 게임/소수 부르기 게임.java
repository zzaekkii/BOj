// package boj.no25632_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final String YONGTAE = "yt";
    private static final String YUJIN = "yj";

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();
    private static final PrimeGame primeGame = new PrimeGame();

    public static void main(String[] args) throws IOException {
        List<Integer> yongtae = primeGame.getPrimes(inputView.readPrimeBound());
        List<Integer> yujin = primeGame.getPrimes(inputView.readPrimeBound());

        yongtae.sort(new PrimeGameComparator());
        yujin.sort(new PrimeGameComparator());

        outputView.printResult(getWinner(yongtae, yujin));
    }

    private static String getWinner(List<Integer> yongtae, List<Integer> yujin) {
        ArrayDeque<Integer> yongtaes = new ArrayDeque<>(yongtae);
        ArrayDeque<Integer> yujins = new ArrayDeque<>(yujin);
        while (true) {
            while (!yongtaes.isEmpty() && !primeGame.canUse(yongtaes.peekFirst())) {
                yongtaes.pollFirst();
            }
            if (yongtaes.isEmpty()) {
                return YUJIN;
            }
            primeGame.usePrime(yongtaes.pollFirst());

            while (!yujins.isEmpty() && !primeGame.canUse(yujins.peekFirst())) {
                yujins.pollFirst();
            }
            if (yujins.isEmpty()) {
                return YONGTAE;
            }
            primeGame.usePrime(yujins.pollFirst());
        }
    }

    static final class PrimeGameComparator implements Comparator<Integer> {

        @Override
        public int compare(Integer o1, Integer o2) {
            return primeGame.getPrimeCount(o2) - primeGame.getPrimeCount(o1);
        }
    }

    static final class PrimeGame {

        private static final int MIN = 2;
        private static final int MAX = 1_000;
        private final boolean[] primes = new boolean[MAX + 1];
        private final int[] primeCount = new int[MAX + 1];


        PrimeGame() {
            Arrays.fill(primes, true);
            for (int i = MIN; i <= MAX; i++) {
                for (int j = i + i; j <= MAX; j += i) {
                    primes[j] = false;
                }
            }
        }

        public void usePrime(int prime) {
            primeCount[prime] = 0;
        }

        public List<Integer> getPrimes(PrimeBound bound) {
            int min = bound.min;
            int max = bound.max;
            List<Integer> primesToReturn = new ArrayList<>();
            for (int i = min; i <= max; i++) {
                if (primes[i]) {
                    primesToReturn.add(i);
                    primeCount[i] += 1;
                }
            }
            return primesToReturn;
        }

        public boolean canUse(int prime) {
            return primeCount[prime] > 0;
        }

        public int getPrimeCount(int prime) {
            return primeCount[prime];
        }
    }

    static final class PrimeBound {
        private final int min;
        private final int max;

        PrimeBound(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }


    static final class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public PrimeBound readPrimeBound() throws IOException {
            StringTokenizer values = new StringTokenizer(br.readLine());
            int min = Integer.parseInt(values.nextToken());
            int max = Integer.parseInt(values.nextToken());
            return new PrimeBound(min, max);
        }
    }

    static final class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(String winner) throws IOException {
            bw.write(winner + "\n");
            bw.flush();
        }
    }
}
