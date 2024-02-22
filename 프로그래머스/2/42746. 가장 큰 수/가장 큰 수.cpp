#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    int num1= stoi(to_string(a) + to_string(b));
    int num2= stoi(to_string(b) + to_string(a));
    return num1 > num2;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    
    
    for(int i=0; i<numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }
    
    if(numbers[0] == 0){
        answer = '0';
    }
    
    return answer;
}