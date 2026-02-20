
import java.util.*;

class Main {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n+1];
		for(int i=1; i<n+1; i++){
			arr[i] = sc.nextInt();
		}

		int[] dp = new int[n+1];
		dp[0] = 0;
		dp[1] = arr[1];
		if(n<2) {
			System.out.println(dp[1]);
			return;
		}
		dp[2] = arr[2]+arr[1];
		for(int i=3; i<n+1; i++){
			dp[i] = Math.max(arr[i]+arr[i-1]+dp[i-3], Math.max(arr[i]+dp[i-2],dp[i-1]));
		}
		System.out.println(dp[n]);
	}
}


