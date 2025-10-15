
import java.util.*;

public class Main {

	static class stack{
		private int top;
		private ArrayList<Integer> arr;

		public stack(){
			top = -1;
			arr = new ArrayList<>();
		}

		public void push(int x){
			top++;
			arr.add(top,x);
		}
		public int pop(){
			if(top == -1){
				return -1;
			}
			int ret = arr.get(top);
			arr.remove(top);
			top--;
			return ret;
		}
		public int size(){
			return top+1;
		}
		public int isEmpty(){
			if(top==-1){
				return 1;
			}
			return 0;
		}
		public int top(){
			if(top==-1){
				return -1;
			}
			return arr.get(top);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		stack st = new stack();

		for (int i = 0; i < n; i++) {
			String order = sc.next();

			if (order.equals("push")) {
				int num = sc.nextInt();   // push일 때만 숫자 읽기
				st.push(num);
			} else if (order.equals("pop")) {
				System.out.println(st.pop());
			} else if (order.equals("size")) {
				System.out.println(st.size());
			} else if (order.equals("isEmpty") || order.equals("empty")) { // 둘 다 대응
				System.out.println(st.isEmpty());
			} else if (order.equals("top")) {
				System.out.println(st.top());
			}
		}
	}

}