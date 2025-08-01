import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        // 1) 정렬해서 가장 빠른/느린 심사관 찾기
        Arrays.sort(times);
        long left  = times[0];
        long right = (long) times[times.length - 1] * n;
        long result = right;

        // 2) 이분 탐색
        while (left <= right) {
            long mid = (left + right) >>> 1;  // overflow 방지
            // mid 시간 동안 몇 명 처리 가능한지 계산
            long judged = 0;
            for (int t : times) {
                judged += mid / t;
                if (judged >= n) break;  // 충분하면 중단
            }

            if (judged >= n) {
                result = mid;        // mid로 모두 처리 가능
                right  = mid - 1;    // 더 짧게도 가능한지 탐색
            } else {
                left = mid + 1;      // mid 시간에 부족 → 늘리기
            }
        }

        return result;
    }
}

/*
입국심사 받는 N 이 10억명..
심사관 심사시간 최대 10억분... 1~10만명이 있음

극단 : 10억분 걸리는 심사는 안가는게...

7 14 21 28 
10 20 30
1만
*/