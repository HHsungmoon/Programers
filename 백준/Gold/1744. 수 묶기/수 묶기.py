
a = int(input())
num_list = []
for i in range(0,a):
    num = int(input())
    num_list.append(num)

num_list.sort()

answer = 0
minus_list =[]
zero_list=[]
plus_list=[]

for i in num_list:
    if i<0:
        minus_list.append(i)
    elif i == 0:
        zero_list.append(i)
    elif i == 1:
        answer +=1
    else:
        plus_list.append(i)

plus_list.sort(reverse=True)
for i in range(0, int(len(plus_list)/2)):
    answer += plus_list[i*2]* plus_list[i*2+1]
if len(plus_list)%2 ==1:
    answer += plus_list[len(plus_list)-1]

for i in range(0, int(len(minus_list)/2)):
    answer += minus_list[i*2]* minus_list[i*2+1]
if len(minus_list)%2 == 1:
    if len(zero_list) == 0:
        answer += minus_list[len(minus_list)-1]

print(answer)