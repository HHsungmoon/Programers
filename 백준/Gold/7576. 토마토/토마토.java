import java.util.*;
import java.lang.*;
import java.io.*;

class Point {
    public int x;
    public int y;
    public int cnt; 
    Point(int x, int y, int cnt){
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }
}

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        // 첫 번째 줄에서 M, N 읽기
        int M = scanner.nextInt(); // 가로 칸 수
        int N = scanner.nextInt(); // 세로 칸 수

        // 입력 데이터를 읽기 위해 input 함수를 호출
        int[][] box = input(scanner, N, M);

        Queue<Point> stque = new LinkedList<>();
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                if(box[y][x] == 1){
                    stque.add(new Point(x, y, 1));
                }
            }
        }

        box = BFS(stque, box, N, M);

        boolean tf = true; int max_num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(box[i][j] == 0) {
                    tf = false;
                    break;
                }
                if(box[i][j] > max_num) 
                    max_num = box[i][j];
            }
        }

        if(!tf) 
            System.out.println(-1);
        else
            System.out.println(max_num - 1);
    }

    public static int[][] input(Scanner scanner, int N, int M) {
        // 상자를 저장할 2차원 배열 생성
        int[][] box = new int[N][M];

        // N개의 줄에서 상자 상태 읽기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                box[i][j] = scanner.nextInt();
            }
        }

        return box; // 입력된 2차원 배열 반환
    }

    public static int[][] BFS(Queue<Point> stque, int[][] box, int N, int M){
        int[] dirx = {1, -1, 0, 0};
        int[] diry = {0, 0, 1, -1};
        
        while(!stque.isEmpty()){
            Point tp = stque.poll(); // poll로 큐에서 가져오면서 제거

            for(int i = 0; i < 4; i++){
                int nx = tp.x + dirx[i];
                int ny = tp.y + diry[i];
                
                if(nx >= 0 && nx < M && ny >= 0 && ny < N
                  && box[ny][nx] == 0){
                    box[ny][nx] = tp.cnt + 1;
                    stque.add(new Point(nx, ny, tp.cnt + 1));
                }
            }
        }
        return box;
    }
}