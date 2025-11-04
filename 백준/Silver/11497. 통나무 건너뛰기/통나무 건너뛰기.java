import java.util.*;

/*
public class Main {
	public static void main(String[] args) {

	}
}
*/

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0; i<n; i++) {
			int k=sc.nextInt();
			ArrayList<Integer> arr = new ArrayList<>();
			ArrayList<Integer> arr2 = new ArrayList<>();
			for(int j=0; j<k; j++) {
				arr.add(sc.nextInt());
				arr2.add(0);
			}
			Collections.sort(arr);
			int start = 0; int end = k-1;
			for(int j=0; j<k; j++) {
				if (j % 2 == 0) {
					arr2.set(start, arr.get(j));
					start++;
				} else {
					arr2.set(end, arr.get(j));
					end--;
				}
			}
			int max = 0;
			for(int j=0; j<k-1; j++) {
				int dif = Math.abs(arr2.get(j)-arr2.get(j+1));
				if(dif>max) {
					max = dif;
				}
			}
			int dif = Math.abs(arr2.get(k-1)-arr2.get(0));
			if(dif>max) {
				max = dif;
			}

			System.out.println(max);
		}
	}
}
