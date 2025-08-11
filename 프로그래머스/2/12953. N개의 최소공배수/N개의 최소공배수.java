import java.util.*;

class Solution {
    public int solution(int[] arr) {
        long lcm = arr[0];
        for (int i = 1; i < arr.length; i++) {
            lcm = lcm(lcm, arr[i]);
            if (lcm > Integer.MAX_VALUE) throw new ArithmeticException("overflow");
        }
        return (int) lcm;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b; // 곱하기 전에 나눠서 overflow 위험 낮춤
    }
}
