import java.util.*;

class Solution {
    public long solution(int[] sequence) {
        long answer = 0;

        List<Long> pers1 = new ArrayList<>();
        List<Long> pers2 = new ArrayList<>();

        if (sequence.length == 1) {
            answer = Math.max(sequence[0], -sequence[0]);
            return answer;
        }

        for (int i = 0; i < sequence.length; i += 2) {
            pers1.add((long) sequence[i]);
            pers2.add(-(long) sequence[i]);

            if (i + 1 < sequence.length) {
                pers1.add(-(long) sequence[i + 1]);
                pers2.add((long) sequence[i + 1]);
            }
        }

        long num1 = calcPerse(pers1);
        long num2 = calcPerse(pers2);
        answer = Math.max(num1, num2);

        return answer;
    }

    public long calcPerse(List<Long> pers) {
        List<Long> dp = new ArrayList<>();
        dp.add(pers.get(0));

        for (int i = 1; i < pers.size(); i++) {
            if (dp.get(i - 1) > 0) {
                dp.add(dp.get(i - 1) + pers.get(i));
            } else {
                dp.add(pers.get(i));
            }
        }

        return Collections.max(dp);
    }
}
