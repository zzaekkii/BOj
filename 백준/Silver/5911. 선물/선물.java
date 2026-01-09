// package boj.no5911_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws IOException {
        Problem problem = getProblem();
        List<Gift> gifts = getGifts(problem.friendCount);
        gifts.sort(null);

        int answer = 0;
        for (int i = 0; i < problem.friendCount; i++) {
            List<Gift> giftsThatIstDiscount = new ArrayList<>(gifts);
            long currentMoney = problem.money;
            Gift gift = giftsThatIstDiscount.get(i);
            int origin = giftsThatIstDiscount.get(i).price;
            giftsThatIstDiscount.get(i).discount();
            giftsThatIstDiscount.sort(null);

            int count = 0;
            for (int j = 0; j < problem.friendCount; j++) {
                currentMoney -= giftsThatIstDiscount.get(j).getTotal();

                if (currentMoney < 0) {
                    break;
                }
                count += 1;
            }

            gift.revert(origin);
            answer = Math.max(answer, count);
        }

        showResult(answer);
    }

    private static Problem getProblem() throws IOException {
        return inputView.readProblem();
    }

    private static List<Gift> getGifts(int friendCount) throws IOException {
        return inputView.readGifts(friendCount);
    }

    private static void showResult(int count) throws IOException {
        outputView.printResult(count);
    }


    static final class Problem {
        private final int friendCount;
        private final int money;

        Problem(int friendCount, int money) {
            this.friendCount = friendCount;
            this.money = money;
        }
    }

    static final class Gift implements Comparable<Gift> {
        private int price;
        private final int fee;

        Gift(int price, int fee) {
            this.price = price;
            this.fee = fee;
        }

        public void revert(int origin) {
            this.price = origin;
        }

        public void discount() {
            this.price /= 2;
        }

        public int getTotalWithDiscount() {
            return price / 2 + fee;
        }

        public int getTotal() {
            return price + fee;
        }

        @Override
        public int compareTo(Gift o) {
            if (getTotal() != o.getTotal()) {
                return getTotal() - o.getTotal();
            }
            if (fee != o.fee) {
                return fee - o.fee;
            }
            return price - o.price;
        }
    }


    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public Problem readProblem() throws IOException {
            StringTokenizer values = new StringTokenizer(br.readLine());
            int friendCount = Integer.parseInt(values.nextToken());
            int money = Integer.parseInt(values.nextToken());
            return new Problem(friendCount, money);
        }

        public List<Gift> readGifts(int friendCount) throws IOException {
            List<Gift> gifts = new ArrayList<>();
            for (int i = 0; i < friendCount; i++) {
                StringTokenizer values = new StringTokenizer(br.readLine());
                int price = Integer.parseInt(values.nextToken());
                int fee = Integer.parseInt(values.nextToken());
                gifts.add(new Gift(price, fee));
            }
            return gifts;
        }
    }

    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(int count) throws IOException {
            bw.write(count + "\n");
            bw.flush();
        }
    }
}
