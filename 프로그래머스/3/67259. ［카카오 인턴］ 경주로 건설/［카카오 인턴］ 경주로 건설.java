import java.util.*;


class Solution {
    private static class Node{
        int x,y;
        int price;
        int dir;
        
        public Node(int x, int y, int price, int dir){
            this.x = x;
            this.y = y;
            this.price = price;
            this.dir = dir;
        }
    }
    
    private static final int[] dx = { -1, 0, 1, 0 };
    private static final int[] dy = { 0, -1, 0, 1 };
    
    public int solution(int[][] board) {
        int answer = 0;
        
        answer = BFS(board);

        return answer;
    }
    
    int BFS(int[][] board){
        int len = board.length;
        Queue<Node> que = new LinkedList<>();
        int[][] visited = new int[len][len];
        
        for(int i=0; i<len; i++){
            for(int t=0; t<len; t++){
                if(board[i][t] == 1)
                    visited[i][t] = -1;
                else
                    visited[i][t] = 100000000;
            }
        }
        
        visited[0][0] = 0;
        que.offer(new Node(0,0,0,2));
        que.offer(new Node(0,0,0,3));
        
        while(!que.isEmpty()){
            Node cur = que.poll();
            
            for(int i=0; i<4; i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nprice;
                int ndir = i;
                if(i == cur.dir){ // 같은방향
                    nprice = cur.price + 100;
                } else if((cur.dir + 1)%4 == i || (cur.dir+3)%4 == i) { // 코너
                    nprice = cur.price + 100 + 500;
                } else{ //반대방향
                    continue;
                }
                
                if(nx>=0 && nx<len && ny>=0 && ny<len){
                    if(board[nx][ny] == 0 && visited[nx][ny] >= nprice){
                        que.offer(new Node(nx,ny,nprice,ndir));
                        visited[nx][ny] = nprice;
                    }
                    else if(board[nx][ny] == 0 && visited[nx][ny]+500 >= nprice){
                        que.offer(new Node(nx,ny,nprice,ndir));
                    }
                }
                
            }
        
        }

        return visited[len-1][len-1];
    }
}


/*
일단.. 최단경로 방식으로는.. 예외가 많아서 
BFS+가중치 방식으로 풀어야 하나..

25*25 최대 625
*/