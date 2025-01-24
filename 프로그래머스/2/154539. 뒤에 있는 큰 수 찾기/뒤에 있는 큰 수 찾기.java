import java.util.Stack;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {

        // -1로 원소 채우기
        int[] result = new int[numbers.length];
        Arrays.fill(result, -1);

        // 스택
        Stack<Integer> stack = new Stack<Integer>();

        // 뒤에서부터 검사
        for(int i = numbers.length-1; i>-1; i--){

            // stack이 비어있지 않고
            // 현재 숫자(numbers[i])가 stack의 맨 위 원소(stack.peek())보다 크거나 같으면
            // 현재 숫자(numbers[i])가 뒤에 숫자보다 크므로 stack 맨 위 원소 삭제
            while (!stack.empty() && numbers[i] >= stack.peek()){
                stack.pop();
            }

            // stack이 비어있지 않은 경우
            // 현재 숫자(numbers[i])의 바로 뒤에 큰 수를 찾았으므로
            // result[i]에 대입
            if(!stack.empty()){
                result[i] = stack.peek();
            }

            // stack에 현재 숫자(numbers[i]) 추가
            stack.push(numbers[i]);
        }

        return result;
    }
}
