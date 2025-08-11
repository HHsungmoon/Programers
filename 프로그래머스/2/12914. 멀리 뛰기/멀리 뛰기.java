import java.util.*;

class Solution {
    public long solution(int n) {
        final int MOD = 1234567;
        if (n <= 2) 
            return n;
        long a = 1, b = 2;
        
        for (int i = 3; i <= n; i++) {
            long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return b;
    }
}

/*
피보나치 문제. f(n) = f(n-1)+f(n-2)

*/