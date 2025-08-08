import java.util.*;

class Solution {
    
    class Node{
        public String name;
        public int cash;
        public Node parent;
        public ArrayList<Node> child;
        
        public Node(String name, int cash, Node parent){
            this.name = name;
            this.cash = cash;
            this.parent = parent;
            this.child = new ArrayList<Node>();
        }
    }
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        
        
        Node center = new Node("-", 0, null);
        ArrayList<Node> tmp = new ArrayList<>();
        tmp.add(center);
        
        for(int i=0; i<enroll.length; i++){
            if(referral[i].equals("-")){  // 센터를 parent로 등록
                Node newNode = new Node(enroll[i], 0, center);
                center.child.add(newNode);
                tmp.add(newNode);
            }else{
                for(int t=1; t<tmp.size(); t++){
                    if(tmp.get(t).name.equals(referral[i])){
                        Node newNode = new Node(enroll[i], 0, tmp.get(t));
                        tmp.get(t).child.add(newNode);
                        tmp.add(newNode);
                        break;
                    }   
                }
            }
        }

        
        int len = seller.length;
        System.out.println(tmp.size());
        for(int i=0; i<len; i++){
            int idx=0;
            for(idx=0; idx<tmp.size(); idx++){
                if(tmp.get(idx).name.equals(seller[i])){
                    
                    int price = amount[i] * 100;
                    Node node = tmp.get(idx);
                    //System.out.println("" + price);
                    while(node != null){
                        if(price<10){
                            node.cash += price;
                            break;
                        }
                        int upper = price/10;
                        node.cash += price - upper;
                        //System.out.println(node.name + " " + node.cash);
                        node = node.parent;
                        price=upper;
                    }
                }
            }
        }
        
        int[] answer = new int[tmp.size()-1];

    
        for(int i=1; i<tmp.size(); i++){
            answer[i-1] = tmp.get(i).cash;
        }
        /*
        for(int i=0; i<tmp.size(); i++){
            System.out.print(tmp.get(i).name + " > ");
            ArrayList<Node> child = tmp.get(i).child;
            for(int t=0; t<child.size(); t++){
                System.out.print(child.get(t).name + " ");
            }
            System.out.println();
        }
        */
 
        return answer;
    }
    
    
}