import java.util.*;

/*
public class Main {
	public static void main(String[] args) {

	}
}
*/

public class Main {

	static class Time{
		int start, end;
		Time(int start, int end){
			this.start = start;
			this.end = end;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		ArrayList<Time> times = new ArrayList<>();
		for(int i=0; i<n; i++){
			int start = scanner.nextInt();
			int end = scanner.nextInt();
			times.add(new Time(start, end));
		}
		times.sort(Comparator.comparingInt((Time t)->t.start).thenComparing(t->t.end));

		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(Time t : times){
			if(!pq.isEmpty() && pq.peek() <= t.start){
				pq.poll();
			}
			pq.offer(t.end);
		}
		System.out.println(pq.size());
	}
}