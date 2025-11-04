import java.util.*;

public class Solution {
    // n: 1..n 중 5개 선택, q: 시도들(각 5개), ans: 각 시도에서의 일치 개수
    public int solution(int n, int[][] q, int[] ans) {
        int m = q.length;

        // 각 시도를 비트마스크로 전처리 (1..n -> bit 0..n-1)
        int[] trialMask = new int[m];
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int v : q[i]) {
                mask |= (1 << (v - 1));
            }
            trialMask[i] = mask;
        }

        // 모든 5개 조합을 생성하며 검증
        int count = 0;
        // 간단히 5중 루프(최대 30이라 충분히 빠름)
        for (int a = 1; a <= n - 4; a++) {
            for (int b = a + 1; b <= n - 3; b++) {
                for (int c = b + 1; c <= n - 2; c++) {
                    for (int d = c + 1; d <= n - 1; d++) {
                        for (int e = d + 1; e <= n; e++) {
                            int mask = 0;
                            mask |= (1 << (a - 1));
                            mask |= (1 << (b - 1));
                            mask |= (1 << (c - 1));
                            mask |= (1 << (d - 1));
                            mask |= (1 << (e - 1));

                            boolean ok = true;
                            for (int i = 0; i < m; i++) {
                                int inter = mask & trialMask[i];
                                if (Integer.bitCount(inter) != ans[i]) {
                                    ok = false;
                                    break;
                                }
                            }
                            if (ok) count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    // 참고: 재귀 조합 생성으로도 가능 (아래는 사용 안 함)
    // private void dfs(int n, int idx, int picked, int mask, int[] trialMask, int[] ans, int[] res) { ... }
}
