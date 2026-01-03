// package boj.no18242;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final InputView inputView = new InputView();
    private static final OutputView outputView = new OutputView();

    public static void main(String[] args) throws Exception {
        final Board board = inputView.readBoard();
        final Square square = board.findSquare();
        final Direction answer = square.findMissingSide(board);
        showAnswer(answer);
    }

    private static void showAnswer(Direction answer) throws Exception {
        outputView.printAnswer(answer);
    }

    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Board readBoard() throws Exception {
            StringTokenizer st = new StringTokenizer(br.readLine());
            final int height = Integer.parseInt(st.nextToken());
            final int width = Integer.parseInt(st.nextToken());

            List<String> board = new ArrayList<>(height);

            for (int h = 0; h < height; h++) {
                board.add(br.readLine());
            }

            return new Board(board, height, width);
        }

    }

    static class Square {

        private final Position leftTop;
        private final int size;

        Square(Position leftTop, int size) {
            this.leftTop = leftTop;
            this.size = size;
        }

        public static Square fromLeftTop(Position start, Board board) {
            int width = 1;
            while (board.isPainted(start.move(Direction.RIGHT, width))) {
                width += 1;
            }

            int height = 1;
            while(board.isPainted(start.move(Direction.DOWN, height))) {
                height += 1;
            }

            final int length = Math.max(height, width);

            return new Square(start, length);
        }

        public Direction findMissingSide(Board board) {
            for (Direction dir : Direction.values()) {
                if (!board.isPainted(middleOfSide(dir))) {
                    return dir;
                }
            }
            throw new IllegalArgumentException();
        }

        private Position middleOfSide(Direction dir) {
            final int mid = size / 2;
            return switch (dir) {
                case UP -> new Position(leftTop.row, leftTop.col + mid);
                case RIGHT -> new Position(leftTop.row + mid, leftTop.col + size - 1);
                case DOWN -> new Position(leftTop.row + size - 1, leftTop.col + mid);
                case LEFT -> new Position(leftTop.row + mid, leftTop.col);
            };
        }
    }

    static class Board {

        private static final char PAINTED = '#';
        private static final char UNPAINTED = '.';

        private final List<String> map;
        private final int height;
        private final int width;

        public Board(List<String> map, int height, int width) {
            this.map = map;
            this.height = height;
            this.width = width;
        }

        public Square findSquare() {
            final int height = map.size();
            final int width = map.get(0).length();

            for (int r = 0; r < height; r++) {
                for (int c = 0; c < width; c++) {
                    if (map.get(r).charAt(c) == PAINTED) {
                        return Square.fromLeftTop(new Position(r, c), this);
                    }
                }
            }
            throw new IllegalArgumentException();
        }

        public boolean isPainted(Position position) {
            if (isInside(position)) {
                return getCell(position) == PAINTED;
            }
            return false;
        }

        private boolean isInside(Position position) {
            return position.row >= 0 && position.row < height
                && position.col >= 0 && position.col < width;
        }

        private char getCell(Position position) {
            return map.get(position.row).charAt(position.col);
        }
    }

    // 백준에는 Java 15라서 record가 없네
    /*record Position(
        int row,
        int col
    ) {*/
    static class Position {

        private final int row;
        private final int col;

        Position(int row, int col) {
            this.row = row;
            this.col = col;
        }

        Position move(final Direction direction, int size) {
            return new Position(
                row + direction.getDr() * size,
                col + direction.getDc() * size
            );
        }
    }

    /**
     * 방향 탐색
     */
    enum Direction {
        LEFT(0, -1, "LEFT"),
        RIGHT(0, 1, "RIGHT"),
        UP(-1, 0, "UP"),
        DOWN(1, 0, "DOWN");

        private final int dr;
        private final int dc;
        private final String label;

        Direction(final int dr, final int dc, final String label) {
            this.dr = dr;
            this.dc = dc;
            this.label = label;
        }

        public int getDr() {
            return dr;
        }

        public int getDc() {
            return dc;
        }

        public String getLabel() {
            return label;
        }
    }


    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printAnswer(Direction answer) throws Exception {
            bw.write(answer.getLabel());
            bw.flush();
        }
    }
}
