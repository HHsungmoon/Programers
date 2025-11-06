import java.util.*;


public class Main {

	static int r, c;
	static int[][] board;
	static int[] dy = {-1,0,1};
	static int ans = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		r = sc.nextInt();
		c = sc.nextInt();
		board = new int[r+2][c];
		sc.nextLine();
		for(int y = 1; y < r+1; y++){
			String tmp = sc.nextLine();
			for(int x = 0; x < c; x++){
				if(tmp.charAt(x) == '.'){
					board[y][x] = 0;
				}else if(tmp.charAt(x) == 'x'){
					board[y][x] = -1;
				}
			}
		}
		for(int i=0;i<c;i++){
			board[0][i] = -1;
			board[r+1][i] = -1;
		}

		for(int i=1; i<=r; i++){
			if(DFS(i,0)){
				ans++;
			}
		}
		System.out.println(ans);
	}

	public static boolean DFS(int y, int x){
		board[y][x] = 1;
		if(x==c-1) return true;

		for(int i=0; i<3; i++){
			int ny = y+dy[i];
			int nx = x+1;

			if(board[ny][nx]==0){
				if(DFS(ny,nx)){
					return true;
				}
			}
		}
		return false;
	}
}

