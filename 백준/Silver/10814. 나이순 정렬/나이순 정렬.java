// package boj.no10814_oop;

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
        List<User> users = inputView.readUsers(inputView.readUserCount());
        users.sort(null);
        outputView.printResult(users);
    }

    static final class User implements Comparable<User> {
        private final int age;
        private final String name;
        private final int sequence;

        private static int TOTAL_USERS = 0;

        private User(int age, String name, int sequence) {
            this.age = age;
            this.name = name;
            this.sequence = sequence;
        }

        public static User of(int age, String name) {
            TOTAL_USERS += 1;
            return new User(age, name, TOTAL_USERS);
        }

        @Override
        public int compareTo(User o) {
            if(this.age == o.age) {
                return this.sequence - o.sequence;
            }
            return this.age - o.age;
        }
    }


    static class InputView {

        private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public int readUserCount() throws IOException {
            return Integer.parseInt(br.readLine());
        }

        public List<User> readUsers(int userCount) throws IOException {
            List<User> users = new ArrayList<>();
            for (int i = 0; i < userCount; i++) {
                StringTokenizer values = new StringTokenizer(br.readLine());
                int age = Integer.parseInt(values.nextToken());
                String name = values.nextToken();
                users.add(User.of(age, name));
            }
            return users;
        }
    }

    static class OutputView {

        private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        public void printResult(List<User> users) throws IOException {
            for(User user : users) {
                bw.write(user.age + " " + user.name + "\n");
            }
            bw.flush();
        }
    }
}
