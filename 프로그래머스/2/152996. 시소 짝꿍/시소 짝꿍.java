import java.util.*;

class Solution {
    public long solution(int[] weights) {
        long result = 0;

        // 몸무게의 빈도수를 저장할 Map
        Map<Integer, Long> weightCount = new HashMap<>();

        // 몸무게 빈도 계산
        for (int weight : weights) {
            weightCount.put(weight, weightCount.getOrDefault(weight, 0L) + 1);
        }

        // 가능한 거리 비율
        int[][] ratios = {{2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 4}, {4, 2}, {4, 3}, {4, 4}};

        // 몸무게 조합 탐색
        for (int weight : weightCount.keySet()) {
            long count = weightCount.get(weight);

            // 같은 몸무게끼리 짝꿍이 되는 경우
            if (count > 1) {
                result += count * (count - 1) / 2; // 조합 계산: nC2 = n * (n - 1) / 2
            }

            // 다른 몸무게와의 조합 확인
            for (int[] ratio : ratios) {
                int num = ratio[0];
                int denom = ratio[1];

                // 다른 몸무게 계산
                if (weight * num % denom == 0) {
                    int pairedWeight = weight * num / denom;

                    // 짝꿍이 존재한다면 결과에 추가
                    if (weightCount.containsKey(pairedWeight) && pairedWeight > weight) {
                        result += count * weightCount.get(pairedWeight);
                    }
                }
            }
        }

        return result;
    }
}
