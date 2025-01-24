import java.util.*;

class Times implements Comparable<Times>{
    public int st, end, num;
    public Times(int st, int end,int num){
        this.st=st;
        this.end = end;
        this.num = num;
    }
    
    public int compareTo(Times other){
        if(this.st == other.st)
            return Integer.compare(this.end, other.end);
        return Integer.compare(this.st, other.st);
    }
}

class Solution {
    public int solution(String[][] book_time) {
        int answer = 0;
        
        ArrayList<Times> times = new ArrayList<>();
        for(int i=0; i<book_time.length; i++){
            int start = Integer.parseInt(book_time[i][0].replace(":", ""));
            int end = Integer.parseInt(book_time[i][1].replace(":", ""));
            times.add(new Times(start,end,0));
        }
        
        Collections.sort(times);
        
        ArrayList<Times> used= new ArrayList<>();
        for(int i=0; i<times.size(); i++){
            Times cur = times.get(i);
            boolean tf = false;
            if(!used.isEmpty()){
                for(int t=0; t<used.size(); t++){
                    if(cur.st >= used.get(t).end){
                        used.remove(t);
                        used.add(add10m(cur));
                        tf = true;
                        break;
                    }
                }
            }
            // 사용중가능한 사용된 빈방 없음 
            if(tf==false){
                answer++;
                used.add(add10m(cur));
            }
        }
        
        return answer;
    }
    
    public Times add10m(Times tmp){
        if(tmp.end%100 >=50){
            tmp.end+=50;
        }
        else 
            tmp.end+=10;
        return tmp;
    }
}