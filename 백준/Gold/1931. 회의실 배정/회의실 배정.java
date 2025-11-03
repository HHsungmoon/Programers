import java.util.*;

public class Main {

	static class Meeting{
		int s, e;
		Meeting(int s, int e){
			this.s = s;
			this.e = e;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		Meeting[] meetings = new Meeting[N];
		for(int i=0; i<N; i++){
			meetings[i] = new Meeting(sc.nextInt(), sc.nextInt());
		}

		Arrays.sort(meetings,
			Comparator.comparingInt((Meeting m)->m.e)
				.thenComparing(m->m.s));

		int cnt = 0;
		int last_end = -1;
		for(Meeting m : meetings){
			if(m.s >= last_end){
				cnt++;
				last_end = m.e;
			}
		}
		System.out.println(cnt);
	}
}
