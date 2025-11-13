import java.util.*;


public class Main {

	public static void main(String[] args) {
		int num; ArrayList<Integer> steps = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		steps.add(0);
		for(int i=0; i<num; i++){
			int tmp = sc.nextInt();
			steps.add(tmp);
		}

		int[] dp = new int[num+1];
		dp[0] = 0;
		dp[1] = steps.get(1);
		if(num >= 2){
			dp[2] = steps.get(1)+steps.get(2);
		}
		for(int i=3; i<=num; i++){
			dp[i] = Math.max(dp[i-2]+steps.get(i), dp[i-3]+steps.get(i-1)+steps.get(i));
		}

		System.out.println(dp[num]);
	}


}

