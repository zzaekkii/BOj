import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;
import java.util.Collections;

public class Main {

    static Vector<String> triplesFound = null;

    /* Add a triple to the answer so far. Make sure: i < j < k. */
    private static void addTripleToAnswer(int i, int j, int k) {
        String s = "{" + i + " " + j + " " + k + "}";
        triplesFound.add(s);
    }

    private static void solveTriples(int[] sequence) {

        int n = sequence.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    int[] t = {sequence[i], sequence[j], sequence[k]};
                    Arrays.sort(t);
    
                    long x2 = 1L * t[0] * t[0];
                    long y2 = 1L * t[1] * t[1];
                    long z2 = 1L * t[2] * t[2];
    
                    if (x2 + y2 == z2) {
                        addTripleToAnswer(t[0], t[1], t[2]);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();

        for(int i = 0; i < numCases; i++) 
        {

            int num = sc.nextInt();

            int[] sequence = new int[num];

            for(int j = 0; j < num; j++) 
                sequence[j] = sc.nextInt();

            triplesFound = new Vector<String>();

            solveTriples(sequence);
            
            if(triplesFound.size() == 0) {
                System.out.println("No Pythogorean triples found in the sequence."); 
            } else {

                /* Sort the triples. */
                Collections.sort(triplesFound);

                System.out.print("Found Pythogorean triples: ");
                for(String s : triplesFound) 
                    System.out.print(" " + s);
                System.out.println();
            }
        }
    }
}
