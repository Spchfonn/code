n = int(input('Input : n = '))
arr = []
for i in range(n):
    if(i==0): arr.append(1)
    elif(i==1): arr.append(2)
    else: arr.append(arr[i-1]+arr[i-2])
print('Output : ', arr[n-1])