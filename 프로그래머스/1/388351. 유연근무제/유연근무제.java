import java.util.*;

class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        
        int sat = 6-startday;
        if(sat == -1){
            sat = 6;
        }
        int sun = 7-startday;
        
        for(int i=0; i<schedules.length; i++){
            int tmp = 0;
            int sc = schedules[i];
            if(sc%100 >= 50){
                sc+=50;  
            }else{
                sc+=10;
            }
            for(int d=0; d<7; d++){
                if(d != sat && d!=sun){
                    
                    if(sc >= timelogs[i][d]){
                        tmp++;
                    }
                }
            }
            if(tmp == 5){
                answer++;
            }
        }
        
        
        return answer;
    }
}