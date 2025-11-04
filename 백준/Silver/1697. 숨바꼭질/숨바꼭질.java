import java.util.*;

/*
public class Main {
	public static void main(String[] args) {

	}
}
*/

public class Main {

	static class Node{
		int x, cnt;
		Node(int x, int cnt){
			this.x = x;
			this.cnt = cnt;
		}
	}

	static int[] visited;
	static Queue<Node> que;
	static final int MAX = 100000;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int sbin = scanner.nextInt();
		int bro = scanner.nextInt();
		visited = new int[100000+1];
		Arrays.fill(visited, -1);

		visited[sbin] = 0;
		que = new ArrayDeque<>();
		que.offer(new Node(sbin, 0));

		while (!que.isEmpty()) {
			Node cur = que.poll();
			if (cur.x == bro) {
				System.out.println(cur.cnt);
				return;
			}

			int nx;

			nx = cur.x - 1;
			if (nx >= 0 && visited[nx] == -1) {
				visited[nx] = cur.cnt + 1;
				que.offer(new Node(nx, cur.cnt + 1));
			}

			nx = cur.x + 1;
			if (nx <= MAX && visited[nx] == -1) {
				visited[nx] = cur.cnt + 1;
				que.offer(new Node(nx, cur.cnt + 1));
			}

			nx = cur.x * 2;
			if (nx <= MAX && visited[nx] == -1) { // ★ 0~100000만
				visited[nx] = cur.cnt + 1;
				que.offer(new Node(nx, cur.cnt + 1));
			}
		}

		System.out.println(visited[bro]);

	}
}