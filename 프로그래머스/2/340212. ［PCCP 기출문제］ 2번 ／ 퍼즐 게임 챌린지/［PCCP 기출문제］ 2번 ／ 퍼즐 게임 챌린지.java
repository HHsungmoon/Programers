import java.util.Arrays;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        
        int slv = 1;
        int elv = 100000;
        int mid = (slv+elv)/2;
        while(slv < elv){
            boolean tf = simulate(mid, diffs,times, limit);
            if(tf){ //현재 level에서 성공함 -> lv다운
                elv = mid;
            }
            else{ // 레벨업 해야함
                slv = mid;
            }
            
            int nmid = (slv+elv)/2;
            if(mid == nmid){ // 자동 업데이트 안되는 구역
                if(tf == false) { // 레벨 1 올리기
                    while(mid>0 && simulate(mid, diffs,times, limit)==false){
                        mid += 1;
                    }
                }
                else { // 레벨 1씩 낮추기
                    while(mid>0 && simulate(mid, diffs,times, limit)){
                        mid -= 1;
                    }
                }
                break;
            }
            else{ mid = nmid;}
        }
        
        if(mid == 0)
            mid +=1;
        return mid;
    }
    
    public boolean simulate(int level,int[] diffs, int[] times, long limit){
        int stage = diffs.length;
        long[] stageTime = new long[stage];
        for(int i=0; i<stage; i++){
            int error_cnt = diffs[i]-level;
            if(error_cnt <= 0) { // 레벨이 높아서 안틀리고 진행
                stageTime[i] = times[i];
            }
            else{ // 틀림 발생
                long useTime = (times[i-1]+times[i])*error_cnt+times[i];
                stageTime[i] = useTime;
            }
        }
        
        long sum = Arrays.stream(stageTime).sum();
        //System.out.println("lv: "+ level + "->" +sum);
        if(limit >= sum)
            return true;
        else
            return false;
    }
}