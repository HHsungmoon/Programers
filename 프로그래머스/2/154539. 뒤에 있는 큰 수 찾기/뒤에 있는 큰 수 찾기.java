import java.util.*;
class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<Integer> tmp = new ArrayList<>();
        int tmax = numbers[numbers.length-1];
        
        for(int t=numbers.length-1; t>=0; t--){
            int cnum = numbers[t];
            boolean tf = false;
            
            for(int i=0; i<tmp.size(); i++){
                if(cnum<tmp.get(i)){
                    tf = true;
                    arr.add(tmp.get(i));
                    tmp.add(0,cnum);
                    break;
                }else{
                    tmp.remove(i);
                    i--;
                }
            }
            
            if(tf==false){ // -1 넣기
                tmp.clear();
                tmp.add(cnum);
                arr.add(-1);
            }
        }
        
        Collections.reverse(arr);
        answer = arr.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}