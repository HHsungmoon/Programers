import java.util.*;
class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        
        // 더하기 두종류 
        int flo = num / w; // 0
        int idx = num % w; // 1
        if(idx==0){
            idx = w; flo--;
        }
        if(flo % 2 == 1){
            idx = w - idx + 1;
        }
        boolean dir = true;
        if(flo % 2 == 0) dir = false; // 시작 다음층이 오른쪽으로
        
        int left = (idx-1)*2+1;
        int right = (w-idx)*2+1;
        
        while(num <= n){
            System.out.println(num);
            answer++;
            if(dir){
                num+=left;
                dir = false;
            }
            else{
                num+=right;
                dir = true;
            }
        }
        
        return answer;
    }
}