import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class S004_cc_likecs03 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder result = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < T; t++) {
            String[] input = br.readLine().trim().split("\\s+");
            int N = Integer.parseInt(input[0]);
            int K = Integer.parseInt(input[1]);

            int[] arr = new int[N];
            input = br.readLine().trim().split("\\s+");
            for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(input[i]);

            int missingCount = getMissingCount(K, arr, N);
            result.append(missingCount).append("\n");
        }

        bw.write(result.toString());
        bw.flush();
        bw.close();
        br.close();
    }

    private static int getMissingCount(int k, int[] a, int n) {
        int fullSetSize = 1 << k; // Total possible numbers with k bits

        boolean[] powerSet = new boolean[fullSetSize]; // Boolean array to track reachable numbers
        powerSet[0] = true; // 0 represents an empty set, always reachable, won't be considered

        for (int i = 0; i < n; i++) powerSet[a[i]] = true; // Mark existing numbers in the array

        int missingCount = 0; // Count missing powers of two
        // Iterate over the powers of two
        for (int i = 1; i < fullSetSize; i <<= 1) if (!powerSet[i]) missingCount++;

        return missingCount;
    }
}