import java.util.*;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] dp = new int[num+1];
		for(int i=0; i<num+1; i++) {
			dp[i] = num+1;
		}

		if(num == 1){
			System.out.println(0);
			return;
		}
		if(num < 3){
			System.out.println(1);
			return;
		}
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for(int i=4; i<num+1; i++){
			if(i%6==0){
				dp[i] = Math.min(dp[i/2]+1, dp[i/3]+1);
				dp[i] = Math.min(dp[i], dp[i-1]+1);
			}
			else if(i%3==0){
				dp[i] = Math.min(dp[i-1]+1, dp[i/3]+1);
			}else if(i%2==0){
				dp[i] = Math.min(dp[i-1]+1, dp[i/2]+1);
			}else{
				dp[i] = dp[i-1]+1;
			}
		}
		System.out.println(dp[num]);
	}


}

