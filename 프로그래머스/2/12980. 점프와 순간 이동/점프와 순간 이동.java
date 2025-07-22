import java.util.*;

public class Solution {
    public int solution(int n) {
        int ans = 0;

        while(n > 0){
            if(n % 2 == 0){
                n = n/2;
            }else{
                n = n-1;
                ans+=1;
            }
        }

        return ans;
    }
}

// K이동(K만큼 건전지 씀), x2(건전지X) 두가지
// N이동 -> 최소 건전지수

// 6 -> 3 -> 2 -> 1
// 5000 -> 2500 -> 1250 -> 625(-1) -> 624 -> 312 -> 156 -> 78 -> 39(-1) -> 38 -> 19(-1) -> 18 -> 9(-1) -> 8
// 8->4->2 (-1)