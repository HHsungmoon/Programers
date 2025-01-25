import java.util.*;

class Pair{
    public long num, cnt;
    
    public Pair(long num, long cnt){
        this.num = num;
        this.cnt = cnt;
    }
}

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        
        int[] warr = new int[1001];
        for(int num : weights){
            warr[num] += 1;
        }
        ArrayList<Pair> data = new ArrayList<>();
        for(int i=100; i<=1000; i++){
            if(warr[i] > 0){
                data.add(new Pair(i,warr[i]));
            }
        }
        
        //case = 
        for(Pair tmp : data){
            if(tmp.cnt >= 2){
                answer += tmp.cnt*(tmp.cnt-1)/2;
            }
        }
        
        //case x3, x2
        //case x2, x1
        //case x4, x3
        for(int i=0; i<data.size()-1; i++){
            for(int t=i+1; t<data.size(); t++){
                if(data.get(i).num * 3 == data.get(t).num *2){
                    answer += data.get(i).cnt*data.get(t).cnt;
                }
                if(data.get(i).num * 2 == data.get(t).num){
                    answer += data.get(i).cnt*data.get(t).cnt;
                }
                if(data.get(i).num * 4 == data.get(t).num*3){
                    answer += data.get(i).cnt*data.get(t).cnt;
                }
            }
        }
        
        
    
        return answer;
    }
}