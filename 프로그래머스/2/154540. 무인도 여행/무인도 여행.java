import java.util.*;

class Point{
    public int x,y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    int[][] map;
    int[][] visited;
    
    public int[] solution(String[] maps) {
        int[] answer = {};
        
        map = new int[maps.length][maps[0].length()];
        visited = new int[map.length][map[0].length];
        for(int y=0; y<maps.length; y++){
            for(int x=0; x<maps[0].length(); x++){
                if(maps[y].charAt(x)=='X'){
                    map[y][x] = -1;
                }else{
                    map[y][x] = Integer.parseInt(""+maps[y].charAt(x));
                }
            }
        }
        
        ArrayList<Integer> arr = new ArrayList<>();
        for(int y=0; y<map.length; y++){
            for(int x=0; x<map[0].length; x++){
                if(map[y][x] != -1 && visited[y][x]==0){
                    int num = DFS(new Point(x,y));
                    arr.add(num);
                }
            }
        }
        Collections.sort(arr);
        if(arr.size()==0){
            arr.add(-1);
        }
        answer = arr.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
    
    public int DFS(Point stp){
        
        Stack<Point> stk = new Stack<>();
        stk.push(stp);
        
        int xlen = map[0].length;
        int ylen = map.length;
        
        int[] dirx = {1,-1,0,0};
        int[] diry = {0,0,1,-1};
        
        visited[stp.y][stp.x] = 1;
        int count = map[stp.y][stp.x];
        while(!stk.isEmpty()){
            Point cp = stk.pop();
            
            for(int i=0; i<4; i++){
                Point np = new Point(cp.x+dirx[i], cp.y+diry[i]);
                if(np.x>=0 && np.x<xlen && np.y>=0 && np.y<ylen){
                    if(map[np.y][np.x]>0 && visited[np.y][np.x]==0){
                        count+= map[np.y][np.x];
                        stk.push(np);
                        visited[np.y][np.x] = 1;
                    }
                }
            }
        }
        return count;
    }
}




