import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Queue<Integer> que = new LinkedList<>();
        for(int i=0; i<bridge_length; i++){
            que.add(0);
        }
        int sumw = 0;
        for(int i=0; i<truck_weights.length; i++){
            answer++;
            // 완료된 트럭 빼기
            int out = que.element();
            que.remove();
            sumw -= out;
            
            // 다리에 트럭 올리기
            if(sumw + truck_weights[i] <= weight){
                que.add(truck_weights[i]);
                sumw+= truck_weights[i];
            }
                
            
            else{
                que.add(0);
                i--;
            }
        }
        
        answer += bridge_length;
        
        return answer;
    }
}