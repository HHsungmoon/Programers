import java.util.*;

class NumCnt{
    public int number,cnt;
    public NumCnt(int number, int cnt){
        this.number = number;
        this.cnt = cnt;
    }
}
class Solution {
    public int solution(int x, int y, int n) {
        int answer = 0;
        answer = BFS(x,y,n);
        if(answer == 1000001)
            answer = -1;
        return answer;
    }
    
    public int BFS(int x, int y, int n){
        Queue<NumCnt> que = new LinkedList<>();
        que.add(new NumCnt(y,0));
        
        int ans = 1000001;
        while(!que.isEmpty()){
            NumCnt nc = que.element();
            que.remove();
            
            if(nc.number==x){
                if(nc.cnt < ans){
                    ans = nc.cnt;
                }
            }
            else if(nc.cnt < ans){
                if(nc.number % 3 == 0){
                que.add(new NumCnt(nc.number/3, nc.cnt+1));
                }
                if(nc.number %2 == 0){
                    que.add(new NumCnt(nc.number/2, nc.cnt+1));
                }
                if(nc.number-n >= x){
                    que.add(new NumCnt(nc.number-n, nc.cnt+1));
                }
            }
        }
        return ans;
    }
}