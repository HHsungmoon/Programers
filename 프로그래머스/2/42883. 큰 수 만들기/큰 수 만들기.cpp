#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int st_idx=0;
    int tmp_idx=0;

    cout << typeid(number[3]-'0').name() << endl;
    
    while(k>0)
    {
        int max_num = 0; 
        for(int i=0; i<k+1; i++)
        {
            if(max_num < number[st_idx+i])
            {
                max_num = number[st_idx+i];
                tmp_idx = i;
            }
        }
        if(tmp_idx <= k)
        {
            k -= tmp_idx;
            st_idx = st_idx+tmp_idx+1;
            answer+= max_num;
        }
        
        if(answer.size()==number.size()-k)
            return answer;
    }
    for(int i=st_idx; i<number.size(); i++)
    {
        answer += number[i];
    }
    
    return answer;
}

