import java.util.*;

public class Main {

	static int n;
	static int[][] map;
	static final int[] dx = {-1,1,0,0};
	static final int[] dy = {0,0,-1,1};
	static int[][] visited;
	static Queue<Node> que;

	static class Node{
		int x,y;
		Node(int x, int y){
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		scanner.nextLine();

		map = new int[n][n];
		for(int i=0; i<n; i++){
			String line = scanner.nextLine();
			for(int j=0; j<n; j++){
				map[i][j] = line.charAt(j)-'0';
			}
		}

		int num = 1;
		ArrayList<Integer> size = new ArrayList<>();
		visited = new int[n][n];
		for(int y=0; y<n; y++){
			for(int x=0; x<n; x++){
				if(map[x][y] == 1 && visited[x][y] == 0){
					size.add(BFS(x, y, num));
				}
			}
		}

		Collections.sort(size);
		System.out.println(size.size());
		for(int i=0; i<size.size(); i++){
			System.out.println(size.get(i));
		}
	}

	public static int BFS(int x, int y, int num){
		int size = 1;
		que = new ArrayDeque<>();
		visited[x][y] = 1;
		que.offer(new Node(x,y));
		while(!que.isEmpty()){
			Node tmp = que.poll();
			for(int i=0; i<4; i++){
				int nx = tmp.x+dx[i];
				int ny = tmp.y+dy[i];
				if(nx>=0 && nx < n && ny>=0 && ny<n ) {
					if(visited[nx][ny] == 0 && map[nx][ny] == 1){
						que.offer(new Node(nx, ny));
						visited[nx][ny] = 1;
						size++;
					}
				}
			}
		}

		return size;
	}
}
