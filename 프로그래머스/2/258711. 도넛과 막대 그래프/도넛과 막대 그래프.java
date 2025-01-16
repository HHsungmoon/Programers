import java.util.*;

class Solution {
    public int[] solution(int[][] edges) {
        int[] answer = {0,0,0,0};
        
        int max_node = 0;
        for(int i=0; i<edges.length; i++){
            if(max_node < edges[i][0])
                max_node = edges[i][0];
            if(max_node < edges[i][1])
                max_node = edges[i][1];
        }
        
        ArrayList<ArrayList<Integer>> newEdges = new ArrayList<>();
        for(int i=0; i<max_node+1; i++){
            newEdges.add(new ArrayList<>());
        }
        int[] reachnode = new int[max_node+1];
        
        for(int i=0; i<edges.length; i++){
            reachnode[edges[i][1]] += 1;
            newEdges.get(edges[i][0]).add(edges[i][1]);
        }
        
        for(int i=1; i<max_node+1; i++){
            if(reachnode[i] == 0 && newEdges.get(i).size() >1){
                answer[0] = i;
            }
        }
        //System.out.println("생성노드: "+answer[0]);
        
        int cnode= answer[0];
        for(int i=0; i<edges.length; i++){
            if(edges[i][0] == cnode){
                int tt = getType(newEdges, edges[i][1], max_node);
                answer[tt] += 1;
            }
        }
        
        return answer;
    }
    
    public int getType(ArrayList<ArrayList<Integer>> newEdges, int stnode, int max_node){
        int nxstart = stnode;
        while(true){
            int count = newEdges.get(nxstart).size();;

            if(count == 1){
                nxstart = newEdges.get(nxstart).get(0);
                if(nxstart == stnode){
                    return 1;
                }
            }
            if(count == 2){
                return 3;
            }
            if(count == 0){
                return 2;
            }
        }
    }
}