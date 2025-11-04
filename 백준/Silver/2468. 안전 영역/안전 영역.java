import java.util.*;

/*
public class Main {
	public static void main(String[] args) {

	}
}
*/

public class Main {

	static class Node{
		int x,y;
		Node(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

	static int n;
	static int[][] board;
	static int maxHigh = 0;
	static final int[] dx = {-1,1,0,0};
	static final int[] dy = {0,0,-1,1};

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		board = new int[n][n];
		for(int y=0; y<n; y++){
			for(int x=0; x<n; x++){
				board[y][x] = scanner.nextInt();
				if(board[y][x] > maxHigh)
					maxHigh = board[y][x];
			}
		}

		int answer = 1;
		for(int i=1; i<maxHigh; i++){
			int tmp = BFS(i);
			if(tmp > answer)
				answer = tmp;
		}
		System.out.println(answer);
	}

	public static int BFS(int i){
		int[][] visited = new int[n][n];
		Queue<Node> que = new ArrayDeque<>();
		int size = 0;

		for(int y=0; y<n; y++){
			for(int x=0; x<n; x++){
				if(visited[y][x] == 0 && board[y][x] > i){
					visited[y][x] = 1;
					que.offer(new Node(x,y));
					while(!que.isEmpty()){
						Node cur = que.poll();
						for(int t=0; t<4; t++){
							int nx = cur.x + dx[t];
							int ny = cur.y + dy[t];
							if(nx>=0 && nx<n && ny>=0 && ny<n && visited[ny][nx] == 0 && board[ny][nx] > i){
								visited[ny][nx] = 1;
								que.offer(new Node(nx,ny));
							}
						}
					}
					size++;
				}
			}
		}

		return size;
	}

}