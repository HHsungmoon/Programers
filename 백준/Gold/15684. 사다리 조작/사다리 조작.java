import java.util.*;

public class Main {
	static int N, M, H;
	static int[][] board; // board[H][N-1], 1이면 (c,c+1) 연결

	// 모든 시작 열 i가 끝에서도 i로 도착하는지 확인
	static boolean identityOK() {
		for (int start = 0; start < N; start++) {
			int col = start;
			for (int r = 0; r < H; r++) {
				if (col < N - 1 && board[r][col] == 1) {
					col++; // 오른쪽 이동
				} else if (col > 0 && board[r][col - 1] == 1) {
					col--; // 왼쪽 이동
				}
			}
			if (col != start) return false;
		}
		return true;
	}

	// (r,c)에 가로선을 놓을 수 있는지 (같은 행에서 좌우 인접 금지)
	static boolean canPlace(int r, int c) {
		if (board[r][c] == 1) return false;
		if (c > 0 && board[r][c - 1] == 1) return false;
		if (c < N - 2 && board[r][c + 1] == 1) return false;
		return true;
	}

	// target개를 추가해서 가능 여부 백트래킹(조합 탐색)
	static boolean dfs(int startIdx, int placed, int target) {
		if (placed == target) return identityOK();

		int width = Math.max(0, N - 1);      // 각 행의 후보 위치 수
		int total = H * width;               // 전체 후보 개수

		for (int idx = startIdx; idx < total; idx++) {
			int r = idx / width;
			int c = idx % width;
			if (!canPlace(r, c)) continue;

			board[r][c] = 1;
			if (dfs(idx + 1, placed + 1, target)) return true;
			board[r][c] = 0; // 백트래킹
		}
		return false;
	}

	static int solve() {
		if (identityOK()) return 0;
		for (int k = 1; k <= 3; k++) {
			if (dfs(0, 0, k)) return k;
		}
		return -1;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 입력: N M H (세로선 수, 기존 가로선 수, 가능한 행 수)
		N = sc.nextInt();
		M = sc.nextInt();
		H = sc.nextInt();

		board = new int[H][Math.max(0, N - 1)];

		// a,b는 1-based → 0-based로 변환: a-1, b-1
		for (int i = 0; i < M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int r = a - 1, c = b - 1;
			board[r][c] = 1;
		}

		System.out.println(solve());
	}
}
