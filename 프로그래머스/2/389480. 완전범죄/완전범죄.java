import java.util.*;

class Solution {
    public int solution(int[][] info, int n, int m) {
        final int INF = 1_000_000;

        // dp[a] = A 흔적 합이 a일 때 가능한 최소 B 흔적
        int[] dp = new int[n];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int[] item : info) {
            int aCost = item[0];
            int bCost = item[1];

            int[] next = new int[n];
            Arrays.fill(next, INF);

            for (int aSum = 0; aSum < n; aSum++) {
                int bSum = dp[aSum];
                if (bSum == INF) continue;

                // 1) A가 훔침: A 증가, B 그대로
                int aNew = aSum + aCost;
                if (aNew < n) {
                    next[aNew] = Math.min(next[aNew], bSum);
                }

                // 2) B가 훔침: A 그대로, B 증가
                int bNew = bSum + bCost;
                if (bNew < m) {
                    next[aSum] = Math.min(next[aSum], bNew);
                }
            }

            dp = next;
        }

        // 가능한 것 중 A가 최소인 값 찾기
        for (int a = 0; a < n; a++) {
            if (dp[a] != INF) return a;
        }
        return -1;
    }
}