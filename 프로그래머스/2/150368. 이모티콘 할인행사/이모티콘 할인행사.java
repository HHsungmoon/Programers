import java.util.*;

class Solution {
    
    ArrayList<ArrayList<Integer>> lists = new ArrayList<>();
    
    public int[] solution(int[][] users, int[] emoticons) {
        
        ArrayList<Integer> tmp = new ArrayList<>();
        int len = emoticons.length-1;
        Combi(0, len, tmp);
        
        int new_plus = 0;
        int new_purchase = 0;
        for(int i=0; i<lists.size(); i++){
            int cnt_plus = 0;
            int cnt_purchase = 0;
            
            for(int[] user : users){
                int rate = user[0];
                int price = user[1];
                
                int purchase = 0;
                for(int t=0; t<emoticons.length; t++){
                    int disp = lists.get(i).get(t);
                    if(rate <= disp){
                        purchase += emoticons[t]*(100-disp)/100;
                    }
                }

                if(purchase >= price){ // 플러스가입
                    cnt_plus++;
                } else{
                    cnt_purchase += purchase;
                }
            }
            
            if(cnt_plus == new_plus){
                if(cnt_purchase > new_purchase)
                    new_purchase=cnt_purchase;
            }
            else if(cnt_plus > new_plus){
                new_plus = cnt_plus;
                new_purchase = cnt_purchase;
            }
        }
        
        int[] answer = {new_plus, new_purchase};
        
        return answer;
    }
    
    public void Combi(int dep, int len,ArrayList<Integer> tmp){
        for(int i=0; i<=40; i+=10){
            if(dep==len){
                tmp.add(i);
                lists.add(new ArrayList(tmp));
                tmp.remove(tmp.size()-1);
            } 
            else {
                tmp.add(i);
                Combi(dep+1, len, tmp);   
                tmp.remove(tmp.size()-1);
            }
        }
        
        return;
    }
}