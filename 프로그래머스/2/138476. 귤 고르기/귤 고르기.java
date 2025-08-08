import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        // 1) 크기별 개수 카운트
        Map<Integer, Integer> freq = new HashMap<>();
        for (int x : tangerine) {
            freq.put(x, freq.getOrDefault(x, 0) + 1);
        }

        // 2) 개수만 뽑아 내림차순 정렬
        List<Integer> counts = new ArrayList<>(freq.values());
        counts.sort(Comparator.reverseOrder());

        // 3) 큰 개수부터 누적해서 k 이상 되는 시점의 종류 수 반환
        int used = 0, kinds = 0;
        for (int c : counts) {
            used += c;
            kinds++;
            if (used >= k) break;
        }
        return kinds;
    }
}