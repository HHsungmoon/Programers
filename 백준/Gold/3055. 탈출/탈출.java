import java.util.*;

/*
public class Main {
	public static void main(String[] args) {

	}
}
*/

public class Main {

	static class Node {
		int x,y;
		Node(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

	static final int[] dx = {-1,1,0,0};
	static final int[] dy = {0,0,-1,1};

	static int y;
	static int x;
	static int[][] board;
	static Node water;
	static Node beber;
	static Queue<Node> wque = new LinkedList<>();

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		y = scanner.nextInt();
		x =	scanner.nextInt();
		board = new int[y][x];

		scanner.nextLine();
		for(int i=0;i<y;i++){
			String str = scanner.nextLine();
			for(int j=0;j<x;j++){
				if(str.charAt(j) == 'D'){
					board[i][j] = 2;
				}else if(str.charAt(j) == 'X'){
					board[i][j] = -2;
				}else if(str.charAt(j) == '*'){
					board[i][j] = -1;
					wque.offer(new Node(j,i));
				}else if(str.charAt(j) == 'S'){
					board[i][j] = 0;
					beber = new Node(j,i);
				}else if(str.charAt(j) == '.'){
					board[i][j] = 0;
				}
			}
		}

		int answer = BFS();
		if(answer == -1){
			System.out.println("KAKTUS");
			return;
		}
		System.out.println(answer);
	}

	public static int BFS(){
		Queue<Node> bque = new LinkedList<>();
		bque.offer(beber);
		int[][] visited = new int[y][x];
		visited[beber.y][beber.x] = 1;
		int cnt=0;

		for(int k=0; k<y*x; k++){
			// 턴마다 물 확장
			int wsize = wque.size();
			for(int t=0; t<wsize; t++){
				Node w = wque.poll();
				for(int i=0; i<4; i++){
					int nwx = w.x + dx[i];
					int nwy = w.y + dy[i];
					if(nwx>=0 && nwx<x && nwy>=0 && nwy<y && board[nwy][nwx]==0){
						board[nwy][nwx] = -1;
						wque.offer(new Node(nwx, nwy));
					}
				}
			}

			int size = bque.size();
			if(size==0)
				return -1;
			for(int t=0; t<size; t++){
				Node n = bque.poll();
				for(int i=0; i<4; i++){
					int nbx = n.x + dx[i];
					int nby = n.y + dy[i];
					if(nbx>=0 && nbx<x && nby>=0 && nby<y && board[nby][nbx]>=0 && visited[nby][nbx]==0){
						if(board[nby][nbx]==2){
							return cnt+1;
						}
						visited[nby][nbx]=1;
						bque.offer(new Node(nbx, nby));
					}
				}
			}
			cnt++;
		}
		return -1;
	}
}