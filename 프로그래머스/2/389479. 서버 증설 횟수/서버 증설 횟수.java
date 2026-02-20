class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] server = new int[24+k]; // 0~23까지만 유효
        
        for(int i=0; i<players.length; i++){
            int pnums = players[i];
            if(pnums >= m*(server[i]+1)){ // 증설필요
                int tmp = pnums/m - server[i];
                for(int t=0; t<k; t++){
                    server[i+t] += tmp;
                }
                answer += tmp;
            }
            //System.out.println(i+"~"+(i+1) + " | " + pnums + " | " + server[i] + " | " + answer);
        }

        
        return answer;
    }
}