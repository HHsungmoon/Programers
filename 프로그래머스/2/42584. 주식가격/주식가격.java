class Solution {
    public int[] solution(int[] prices) {
        int len = prices.length;
        int[] answer = new int[len];
        
        //int min=prices[len-1];
        //int max=prices[len-1];
        
        for(int i=len-2; i>=0; i--){
            int num = prices[i];
            int cnt = 0;
            for(int t=i+1; t<len; t++){
                int cnum = prices[t];
                cnt++;
                if(num > cnum){
                    break;
                }
            }
            answer[i] = cnt;
        }
        return answer;
    }
}