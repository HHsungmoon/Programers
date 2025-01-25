import java.util.*;
class Point{
    public int x,y,cnt;
    public Point(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}
class Solution {
    int[][] board;
    int[] dirx = {1,-1,0,0};
    int[] diry = {0,0,1,-1};
    int ylen, xlen;
    public int solution(String[] maps) {
        int answer = 0;
        
        ylen = maps.length; xlen = maps[0].length();
        board = new int[maps.length][maps[0].length()];
        Point start = new Point(0,0,0);
        Point laver = new Point(0,0,0);
        Point end = new Point(0,0,0);
        for(int y=0; y<maps.length; y++){
            for(int x=0; x<maps[0].length(); x++){
                if(maps[y].charAt(x) == 'O')
                    board[y][x] = 1;
                else if(maps[y].charAt(x) == 'S'){
                    start.x = x; start.y = y;
                    board[y][x] = 1;
                }
                else if(maps[y].charAt(x) == 'L'){
                    laver.x = x; laver.y = y;
                    board[y][x] = 1;
                }
                else if(maps[y].charAt(x) == 'E'){
                    end.x = x; end.y = y;
                    board[y][x] = 1;
                }
            }
        }
        
        answer += BFS(start,laver);
        if(answer==-1)return -1;
        
        int cnt = BFS(laver,end);
        if(cnt==-1)return -1;
        
        
        return answer+cnt;
    }
    
    public int BFS(Point stp, Point end){
        boolean[][] visited = new boolean[ylen][xlen];
        Queue<Point> que = new LinkedList<>();
        
        que.add(stp);
        visited[stp.y][stp.x] = true;
        while(!que.isEmpty()){
            Point cur = que.element();
            que.remove();
            
            if(cur.y == end.y && cur.x== end.x){ // 목표 도착
                return cur.cnt;
            }
            
            for(int i=0; i<4; i++){
                Point nxt = new Point(cur.x+dirx[i], cur.y+diry[i],cur.cnt+1);
                if(nxt.x>=0 && nxt.x<xlen && nxt.y>=0 && nxt.y<ylen){
                    if(board[nxt.y][nxt.x]==1 && visited[nxt.y][nxt.x]==false){
                        que.add(nxt);
                        visited[nxt.y][nxt.x]=true;
                    }
                }
            }
        }
        return -1;
    }
}




