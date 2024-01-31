def check_null(mark):
    if mark[0] == 0 and mark[1] == 0: return True
    elif mark[n-1] == 0 and mark[n-2] == 0: return True
    for i in range(1, n-1):
        if mark[i] == 0:
            cnt = 1
            for j in range(i+1, n-1):
                if mark[j] != 0: break
                cnt += 1
            if cnt > 2: return True
    return False

def check_0(i):
    if i == 0:
        if mark[1] == 0: return True
    elif i == n-1:
        if mark[n-2] == 0: return True
    else:
        if mark[i-1] == 0 and mark[i+1] == 0: return True
    return False

def check_1(i):
    if not check_null(mark): return True
    return False

def check_2(i):
    if check_null(mark): return True
    return False

n = int(input('Input 1 : '))
a = input('Input 2 : ')
b = a.split()
mylist = [int(i) for i in b]
index = [0] * n
for i in range(n):
    index[mylist[i]-1] = i
mark = [0] * n
ans = [9] * n
for i in index:
    if check_0(i):
        ans[i] = 0
    elif check_1(i):
        ans[i] = 1
    elif check_2(i):
        ans[i] = 2
    mark[i] = 1
print('Output : ', end = '')
print(ans)