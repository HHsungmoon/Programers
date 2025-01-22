import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // 숫자의 개수
        int[] numarr = new int[N];
        int[] oparr = new int[4]; // 연산자 배열 (4개 고정)

        // 숫자 입력
        for (int i = 0; i < N; i++) {
            numarr[i] = scanner.nextInt();
        }

        // 연산자 입력
        for (int i = 0; i < 4; i++) {
            oparr[i] = scanner.nextInt();
        }

        // 연산자 리스트 생성
        ArrayList<Integer> oplist = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            for (int t = 0; t < oparr[i]; t++) {
                oplist.add(i + 1); // 1: +, 2: -, 3: *, 4: /
            }
        }

        // 중복 제거를 위해 Set 사용
        Set<List<Integer>> permuteSet = new HashSet<>();
        generatePermutations(oplist, 0, permuteSet);

        int max_num=-1000000000; int min_num=1000000000;
        for(List<Integer> plist : permuteSet){
            int res = calculation(numarr, plist);
            if(max_num < res) max_num = res;
            if(min_num > res) min_num = res;
        }

        System.out.println(max_num);
        System.out.println(min_num);
    }

    // 백트래킹으로 순열 생성
    public static void generatePermutations(ArrayList<Integer> oplist, int start, Set<List<Integer>> permuteSet) {
        if (start == oplist.size()) {
            permuteSet.add(new ArrayList<>(oplist)); // Set에 추가 (중복 자동 제거)
            return;
        }

        for (int i = start; i < oplist.size(); i++) {
            Collections.swap(oplist, start, i); // 요소 교환
            generatePermutations(oplist, start + 1, permuteSet); // 다음 단계로 진행
            Collections.swap(oplist, start, i); // 원상 복구
        }
    }
    public static int calculation(int[] numarr, List<Integer> oplist){
        int rest = numarr[0];
        for(int i=0; i<oplist.size(); i++){
            if(oplist.get(i)==1){
                rest += numarr[i+1];
            }else if(oplist.get(i) == 2){
                rest -= numarr[i+1];
            }else if(oplist.get(i) == 3){
                rest *= numarr[i+1];
            }else if(oplist.get(i) == 4){
                rest /= numarr[i+1];
            }
        }
        return rest;
    }
}