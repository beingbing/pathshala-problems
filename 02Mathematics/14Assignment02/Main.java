import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static int MAX = 1000000;
    static int[] spf = null;

    private static void processSpfTill(int n) {
        spf = new int[n+1];

        for (int i = 0; i <= n; i++) spf[i] = i;

        for (int p = 2; p * p <= n; p++)
            if (spf[p] == p)
                for (int multiple = p * p; multiple <= n; multiple += p)
                    if (spf[multiple] == multiple) spf[multiple] = p;
    }

    private static int printDivisorsCount(int x) {
        int divisorsCount = 0;
        while (x != 1) {
            int prime = spf[x];
            while (x % prime == 0) x /= prime;
            divisorsCount++;
        }
        return divisorsCount;
    }

    public static void main (String[] args) throws java.lang.Exception {
        processSpfTill(MAX);
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt(), temp;

            for (int i = 0; i < n; i++) {
                temp = sc.nextInt();
                temp = printDivisorsCount(temp);
                System.out.print(temp);
                if (i != n-1) System.out.print(" ");
            }

            System.out.println();
        }
        sc.close();
    }
}
