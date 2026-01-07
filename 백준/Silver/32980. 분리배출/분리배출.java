// package boj.no32980_oop;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws IOException {
        List<Garbage> garbages = inputView.readGarbages(getCount());
        GarbageCost garbageCost = GarbageCost.of(getCosts());
        long totalCost = 0;
        for (Garbage garbage : garbages) {
            totalCost += garbageCost.getMinimumCost(garbage);
        }
        outputView.printResult(totalCost);
    }

    private static int getCount() throws IOException {
        return inputView.readGarbageCount();
    }

    private static List<Integer> getCosts() throws IOException {
        return inputView.readGarbagesCost();
    }

    //    record Garbage(
    static final class Garbage {
        private final String component;

        Garbage(String component) {
            this.component = component;
        }

        public GarbageType getGarbageType() {
            int garbageSize = component.length();
            char firstElement = component.charAt(0);
            for (int i = 1; i < garbageSize; i++) {
                if (firstElement != component.charAt(i)) {
                    return GarbageType.GENERAL;
                }
            }
            return GarbageType.fromString(String.valueOf(firstElement));
        }

        public int getSize() {
            return component.length();
        }
    }

    static class GarbageCost {
        private final Map<GarbageType, Integer> costs;

        GarbageCost(Map<GarbageType, Integer> costs) {
            this.costs = costs;
        }

        public static GarbageCost of(List<Integer> costs) {
            Map<GarbageType, Integer> garbages = new HashMap<>();
            int idx = 0;
            for (GarbageType garbage : GarbageType.values()) {
                garbages.put(garbage, costs.get(idx));
                idx++;
            }
            return new GarbageCost(garbages);
        }

        public long getMinimumCost(Garbage garbage) {
            long garbageSize = garbage.getSize();
            long generalCost = costs.get(GarbageType.GENERAL) * garbageSize;
            long recycleCost = costs.get(garbage.getGarbageType()) * garbageSize;

            return Math.min(generalCost, recycleCost);
        }
    }

    enum GarbageType {
        PLASTIC("P"),
        CAN("C"),
        VINYL("V"),
        PAPER("S"),
        GLASS("G"),
        STYROFOAM("F"),
        GENERAL("O");

        private final String type;

        GarbageType(String type) {
            this.type = type;
        }

        public static GarbageType fromString(String type) {
            for (GarbageType garbage : GarbageType.values()) {
                if (garbage.type.equals(type)) {
                    return garbage;
                }
            }
            throw new IllegalArgumentException();
        }
    }


    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public int readGarbageCount() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        public List<Garbage> readGarbages(int garbageCount) throws IOException {
            List<Garbage> garbages = new ArrayList<>();

            for (int i = 0; i < garbageCount; i++) {
                garbages.add(new Garbage(br.readLine()));
            }

            return garbages;
        }

        public List<Integer> readGarbagesCost() throws IOException {
            List<Integer> costs = new ArrayList<>();
            String input = br.readLine();
            String[] values = input.split(" ");
            for (String value : values) {
                costs.add(Integer.parseInt(value));
            }
            costs.add(Integer.parseInt(br.readLine()));
            return costs;
        }
    }

    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(long totalCost) throws IOException {
            bw.write(totalCost + "\n");
            bw.flush();
        }
    }
}
