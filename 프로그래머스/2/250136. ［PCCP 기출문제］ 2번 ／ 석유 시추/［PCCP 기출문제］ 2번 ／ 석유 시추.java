import java.util.*;

class Point {
    public int x;
    public int y;
    
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int solution(int[][] land) {
        int answer = 0;
        
        int type_num = 1;
        int[][] data = new int[land.length][land[0].length];
        for(int x=0; x<land[0].length; x++){
            for(int y=0; y<land.length; y++){
                if(land[y][x] == 1 && data[y][x]==0){
                    Point st = new Point(x,y);
                    data = BFS(st, land, data, type_num);
                    type_num++;
                }
            }
        }
            
        int[] types = new int[type_num];
        for(int x=0; x<land[0].length; x++){
            for(int y=0; y<land.length; y++){
                if(data[y][x]!= 0){
                    types[data[y][x]]+=1;
                }
            }
        }
        
        for(int x=0; x<land[0].length; x++){
            ArrayList<Integer> num = new ArrayList<>();
            for(int y=0; y<land.length; y++){
                if(land[y][x] == 1){
                    num.add(data[y][x]);
                }
            }
            Set<Integer> uniq = new HashSet<>(num);
            int sizes = 0;
            for (int value : uniq) {
                sizes += types[value];
            }
            if(answer < sizes){
                answer = sizes;
            }
        }
        
        return answer;
    }
    
    public int[][] BFS(Point st,int[][] land, int[][] data, int type_num){
        int xlen = land[0].length;
        int ylen = land.length;
        
        int[] dirx = {1,-1,0,0};
        int[] diry = {0,0,1,-1};
        
        Queue<Point> que = new LinkedList<>();
        que.add(st);
        data[st.y][st.x] = type_num;
        while(!que.isEmpty()){
            Point tmp = que.element();
            
            for(int i=0; i<4; i++){
                Point np = new Point(tmp.x+dirx[i], tmp.y+diry[i]);
                
                if(np.x>=0 && np.x<xlen && np.y>=0 && np.y<ylen
                  && land[np.y][np.x] == 1 && data[np.y][np.x]==0){
                    data[np.y][np.x] = type_num;
                    que.add(np);
                }
            }
            que.remove();
        }
        
        return data;
    }
}