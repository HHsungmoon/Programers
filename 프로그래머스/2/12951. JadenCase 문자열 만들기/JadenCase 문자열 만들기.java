class Solution {
    public String solution(String s) {
        String answer = "";
        
        Boolean last = false;
        if(s.charAt(s.length()-1) == ' ')
        {
            s += "1";
            last = true;
        }
            
        String[] str = s.split(" ");
        for(int i=0; i<str.length; i++)
        {
            
            if(str[i].length() == 0)
                answer+= " ";
            else
            {
                if(str[i].length() == 1)
                answer += str[i].toUpperCase();
            else if(str[i].length() > 1)
                answer += str[i].substring(0,1).toUpperCase() + str[i].substring(1).toLowerCase();
            
            if(i != str.length-1)
                answer += " ";
            }
            
        }
        if(last == true)
            answer = answer.substring(0,answer.length()-1);
        
        return answer;
    }
}