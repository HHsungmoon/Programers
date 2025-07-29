import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        int[][] dp = new int[triangle.length][triangle.length];
        dp[0][0] = triangle[0][0];
        
        
        for(int i=0; i<triangle.length-1; i++)
        {
            for(int t=0; t<triangle[i].length; t++)
            {
                dp[i+1][t] = Math.max(dp[i+1][t],dp[i][t]+triangle[i+1][t]);
                dp[i+1][t+1] = dp[i][t]+triangle[i+1][t+1];
            }
        }
        

        for(int t=0; t<dp[dp.length-1].length; t++)
        {
            answer = Math.max(answer, dp[dp.length-1][t]);
        }
        
        
        return answer;
    }
}