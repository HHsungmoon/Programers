import java.util.*;

class MineTime implements Comparable<MineTime>{
    public int d;
    public int i;
    public int s;
    
    public MineTime(ArrayList<String> mral){
        this.d = 0;
        this.i = 0;
        this.s = 0;
        //System.out.println(mral.toString());
        for(int i=0; i<mral.size(); i++){
            if(mral.get(i).equals("diamond")){
                this.s += 25;
                this.i += 5;
                this.d += 1;
            }
            else if(mral.get(i).equals("iron")){
                this.s += 5;
                this.i += 1;
                this.d += 1;
            }
            else if(mral.get(i).equals("stone")){
                this.d += 1;
                this.i += 1;
                this.s += 1;
            }
        }
    }
    
    public int compareTo(MineTime other){
        
        if(other.s == this.s){
            if(other.i == this.i){
                return Integer.compare(other.d, this.d);
            }
            return Integer.compare(other.i, this.i);
        }
        return Integer.compare(other.s, this.s);
    }
}

class Solution {
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        
        ArrayList<MineTime> Marr = new ArrayList<>();

        ArrayList<String> input = new ArrayList<>();
        for(int i=0; i<minerals.length; i++){
            input.add(minerals[i]);
            if(input.size()==5){
                MineTime tmpMine = new MineTime(input);
                Marr.add(tmpMine);
                input.clear();
            }
        }
        MineTime tmpMine = new MineTime(input);
        Marr.add(tmpMine);
        
        
        int cntpick = picks[0]+picks[1]+picks[2];
        if(cntpick < Marr.size())
            Marr.subList(cntpick,Marr.size()).clear();
        
        Collections.sort(Marr);
        if(Marr.size()<=picks[0]){
            picks[1]=0; picks[2] = 0;
        }else if(Marr.size()>picks[0] && Marr.size()<=picks[1]+picks[0]){
            picks[2] = 0; picks[1] = Marr.size()-picks[0];
        }else if(Marr.size()>picks[0]+picks[1] && Marr.size()<=picks[2]){
            picks[2] = Marr.size()-picks[0]-picks[1];
        }
        
        int index = 0;
        
        for(int i=1; i<=picks[0]; i++){ // 다이아 곡괭이
            if(index>=Marr.size())
                break;
            //System.out.print("D");
            answer += Marr.get(index).d;
            index++;
        }
        for(int i=1; i<=picks[1]; i++){ // 철 곡괭이
            if(index>=Marr.size())
                break;
            //System.out.print("I");
            answer += Marr.get(index).i;
            index++;
        }
        for(int i=1; i<=picks[2]; i++){ // 돌 곡괭이
            if(index>=Marr.size())
                break;
            //System.out.print("S");
            answer += Marr.get(index).s;
            index++;
        }
        
        return answer;
    }
}