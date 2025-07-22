import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, (o1, o2) -> {
            return o1[1] - o2[1];
        });
        int cnt = targets.length; // 총 요격해야하는 수
    
    
        int idx=0;
        while(cnt>0){
            
            int st = targets[idx][0];
            int ed = targets[idx][1];
            int min_ed = ed;
            int kill_point = 1;
            for(int i = idx+1; i < idx+cnt; i++){
                if(targets[i][0] < ed){
                    // 같이 kill
                    ed = Math.min(targets[i][1], min_ed);
                    kill_point += 1;
                }else{
                    break;
                }
            }
            idx+=kill_point;
            cnt-=kill_point;
            answer+=1;
        }
        
        return answer;
    }

}

// 시작시간 우선 정렬
// 스타팅 포함, 엔드 미포함. 
// 그냥 그리디?