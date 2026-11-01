import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        String answer = switch (n % 2) {
            case 0 -> "even";
            default -> "odd";
        };
        
        System.out.println(n + " is " + answer);
    }
}