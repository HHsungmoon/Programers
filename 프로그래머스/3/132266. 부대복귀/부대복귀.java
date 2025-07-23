import java.util.*;

class Solution {
    List<List<Integer>> graph;

    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        // 인접 리스트 생성
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] road : roads) {
            graph.get(road[0]).add(road[1]);
            graph.get(road[1]).add(road[0]);
        }

        // ✅ destination에서 BFS 한 번 수행 → 전체 최단 거리 저장
        int[] distance = bfsFromDestination(destination, n);

        // source에 대해 거리 조회
        int[] answer = new int[sources.length];
        for (int i = 0; i < sources.length; i++) {
            answer[i] = distance[sources[i]];
        }

        return answer;
    }

    // ✅ destination에서 전체 노드로의 최단거리 BFS
    private int[] bfsFromDestination(int destination, int n) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(destination);
        dist[destination] = 0;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int next : graph.get(current)) {
                if (dist[next] == -1) {
                    dist[next] = dist[current] + 1;
                    queue.offer(next);
                }
            }
        }

        return dist;
    }
}
