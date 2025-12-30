import java.io.*;
import java.util.*;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(br.readLine());

        HashMap<Integer, Integer> prevRanks = new HashMap<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int rank = 0; rank < n; rank++) {
            prevRanks.put(Integer.parseInt(st.nextToken()), rank);
        }

        int maxIncrease = 0;
        List<Integer> players = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int rank = 0; rank < n; rank++) {
            int playerNumber = Integer.parseInt(st.nextToken());
            int prevRank = prevRanks.get(playerNumber);

            int gap = prevRank - rank;
            if (gap > maxIncrease) {
                maxIncrease = gap;
                players.clear();
                players.add(playerNumber);
            } else if (gap == maxIncrease) {
                players.add(playerNumber);
            }
        }

        for (int player : players) {
            bw.write(player + " ");
        }
        bw.flush();
    }
}
