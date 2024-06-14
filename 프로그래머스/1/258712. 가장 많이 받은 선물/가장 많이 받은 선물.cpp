#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;



int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    int fnum = friends.size();
    
    vector<vector<int>> data(fnum+1,vector<int>(fnum+1,0));
    vector<int> next_gift(fnum,0);
    
    for(int i=0; i<gifts.size(); i++)
    {
        size_t pos = gifts[i].find(' ');
        string gi = gifts[i].substr(0, pos);
        string re = gifts[i].substr(pos+1, gifts[i].size());
        
        int giv_id, rec_id;
        for(int t=0; t<fnum; t++)
        {
            if(gi.compare(friends[t])==0)
                giv_id = t;
            if(re.compare(friends[t])==0)
                rec_id = t;
        }
        data[giv_id][rec_id] += 1;
        data[giv_id][fnum] += 1;
        data[fnum][rec_id] += 1;
        
    }
    
    for(int x=0; x<fnum; x++)
    {
        for(int y=x; y<fnum; y++)
        {
            if(x==y)
                continue;
            
            if(data[x][y] > data[y][x]) // x
            {
                next_gift[x] += 1;
            }
            else if(data[x][y] < data[y][x])
            {
                next_gift[y] +=1;
            }
            else // 선물지수 비교 필요
            {
                if(data[x][fnum]-data[fnum][x] > data[y][fnum]-data[fnum][y])
                {
                    next_gift[x] += 1;
                }
                else if(data[x][fnum]-data[fnum][x] < data[y][fnum]-data[fnum][y])
                {
                    next_gift[y] += 1;
                }
            }
        }
    }
    for(int y=0; y<fnum; y++)
    {
        cout << next_gift[y] << " ";
    }
    
    answer = *max_element(next_gift.begin(), next_gift.end());
    /*
    for(int x=0; x<fnum+1; x++)
    {
        for(int y=0; y<fnum+1; y++)
        {
            cout << data[x][y] << " ";
        }
        cout << endl;
    }*/
    
    return answer;
}