class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        pos=nextPos(video_len, pos,op_start,op_end, 0);
        for(String cmd : commands){
            if(cmd.equals("next")){pos=nextPos(video_len, pos,op_start,op_end, 10);}
            if(cmd.equals("prev")){pos=nextPos(video_len, pos,op_start,op_end, -10);}
        }
        
        
        return pos;
    }
    
    public String nextPos(String len, String pos, String start, String end, int com){
        int[] npos = makeTime(pos);
        npos[1] += com;
        
        if(npos[1] >= 60) {npos[0]+=1; npos[1]-=60;}
        else if(npos[1] < 0) {npos[0]-=1; npos[1]+=60;}
        String newpos = npos[0] + ":" + npos[1];
        // 새로운 시간으로 변경
        
        // 시간범위 체크
        if(compareTime("00:00", newpos) == true){ // 시간이 음수
            newpos = "00:00";}
        else if(compareTime(newpos, len) == true){  // 시간 초과
            newpos = len;
        }
        if(compareTime(newpos, start) && compareTime(end, newpos)){ // 오프닝스킵
            newpos = end;
        }
        
        return makeFormat(newpos);
    }
    
    public String makeFormat(String pos){
        String[] tmp = pos.split(":");
        if(tmp[0].length() == 1){tmp[0] = "0"+tmp[0];}
        if(tmp[1].length() == 1){tmp[1] = "0"+tmp[1];}
        
        return tmp[0] + ":" + tmp[1];
    }
    
    public int[] makeTime(String time){
        String[] tmp = time.split(":");
        int[] retTime = new int[2];
        retTime[0] = Integer.valueOf(tmp[0]);
        retTime[1] = Integer.valueOf(tmp[1]);
        return retTime;
    }
    
    public boolean compareTime(String t1, String t2){
        String[] tmp = t1.split(":");
        int t1t = Integer.valueOf(tmp[0]);
        int t1m= Integer.valueOf(tmp[1]);
        
        String[] tmp2 = t2.split(":");
        int t2t = Integer.valueOf(tmp2[0]);
        int t2m= Integer.valueOf(tmp2[1]);
        
        if(t1t < t2t){ // t1<t2 - false
            return false;
        }
        else if(t1t > t2t){ // t1>t2 - true
            return true;
        } 
        else if(t1t==t2t){
            if(t1m < t2m){ return false;}
            if(t1m >= t2m){ return true;}
        }
        
        return true;
    }
}