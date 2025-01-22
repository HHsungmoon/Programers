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
    public int solution(String[] input) {
        int answer = 0;
        
        int xlen = input[0].length();
        int ylen = input.length;
        int[][] board = new int[ylen][xlen];
        
        Point stp = new Point(0,0,0);
        Point glp = new Point(0,0,0);
        
        for(int y=0; y<ylen; y++){
            for(int x=0; x<xlen; x++){
                if(input[y].charAt(x) == 'D'){
                    board[y][x] = -1;
                }else if(input[y].charAt(x) == 'R'){
                    stp.x = x; stp.y=y;
                }else if(input[y].charAt(x) == 'G'){
                    glp.x = x; glp.y=y;
                }
            }
        }
        
        // 어차피 안되는 경우. goal인근에 벽, 장애물 없음. 4면다 장애물,벽
        int[] dirx = {1,-1,0,0};
        int[] diry = {0,0,1,-1};
        boolean dtf = false; int cnt=0;
        for(int i=0; i<4; i++){
            int nx = glp.x+dirx[i];
            int ny = glp.y+diry[i];
            if(nx>=0 && nx<xlen && ny>=0 && ny<ylen){
                if(board[ny][nx] == -1){
                    cnt++;
                }
            }else{
                cnt++;
            }
        }
        if(cnt == 4 || cnt == 0){
            return -1;
        }
        
        // BFS로 탐색하기
        answer = BFS(stp,glp,board,xlen,ylen);
        
        return answer;
    }
    
    public int BFS(Point stp, Point glp, int[][] board, int xlen, int ylen){
        int[] dirx = {1,-1,0,0};
        int[] diry = {0,0,1,-1};
        int[][][] visited = new int[ylen][xlen][4];
        Queue<Point> que = new LinkedList<>();
        que.add(stp);
        
        while(!que.isEmpty()){
            Point cp = que.element();
            que.remove();
            
            for(int i=0; i<4; i++){ // 0오, 1왼, 2하, 3상
                Point np = new Point(cp.x+dirx[i], cp.y+diry[i],cp.cnt+1);
                
                boolean tf=false;
                while(np.x>=0 && np.x<xlen && np.y>=0 && np.y<ylen && board[np.y][np.x]!=-1 && visited[np.y][np.x][i]==0){
                    tf=true;
                    visited[np.y][np.x][i] = 1;
                    np.x += dirx[i]; np.y += diry[i];
                }
                if(tf){
                    np.x -= dirx[i]; np.y-=diry[i];
                    que.add(np);
                    if(np.x==glp.x && np.y==glp.y){
                        return np.cnt;
                    }
                }
                
            }
        }
        return -1;
    }
}