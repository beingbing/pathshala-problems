import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static int[] spf = null;

    private static void processSpfTill(int n) {
        spf = new int[n+1];

        for (int i = 0; i <= n; i++) spf[i] = i;

        for (int p = 2; p * p <= n; p++)
            if (spf[p] == p)
                for (int multiple = p * p; multiple <= n; multiple += p)
                    if (spf[multiple] == multiple) spf[multiple] = p;
    }

    private static void printPrimeFactors(int x) {
        while (x != 1) {
            int prime = spf[x];
            int count = 0;
            while (x % prime == 0) {
                x /= prime;
                count++;
            }
            System.out.println(prime + " " + count);
        }
    }

    public static void main (String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        int[] cases = new int[t];
        int maxNum = 0;

        for (int i = 0; i < t; i++) {
            cases[i] = sc.nextInt();
            maxNum = Math.max(maxNum, cases[i]);
        }

        processSpfTill(maxNum);

        for (int i = 0; i < t; i++)
            printPrimeFactors(cases[i]);
    }
}