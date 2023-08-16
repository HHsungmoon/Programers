num = int(input())
num_list = list(map(int,input().split()))

num_list.sort()
answer =0
for i in range(0, num):
	low=0; high=num-1
	if low==i:
		low+=1
	elif high==i:
		high-=1

	while low<high:
		aa=0
		if (num_list[low] + num_list[high]) < num_list[i]: 
			low += 1
			if low == i:
				low += 1
		elif num_list[low] + num_list[high] > num_list[i]:
			high -= 1
			if high == i:
				high -= 1
		elif num_list[low] + num_list[high] == num_list[i]:
			answer+=1
			break;

print(answer)