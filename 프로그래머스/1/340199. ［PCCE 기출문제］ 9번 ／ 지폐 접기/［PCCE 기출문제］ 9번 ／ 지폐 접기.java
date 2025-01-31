class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        while(isPossible(wallet, bill)==false){
            if(bill[0] > bill[1])
                bill[0] = bill[0]/2;
            else
                bill[1] = bill[1]/2;
            answer+=1;
        }

        return answer;
    }
    
    public boolean isPossible(int[] wallet, int[] bill){
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1])
            return true;
        if(wallet[0] >= bill[1] && wallet[1] >= bill[0])
            return true;
        return false;
    }
}