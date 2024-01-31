def find_maxwall(h):
    ans = []
    for i in range(0, len(h)-1):
        left = max(h[0:i+1])
        right = max(h[i+1:len(h)])
        ans.append(min(left, right))
    return ans

a = input('Input : ')
b = a.split()
high = [int(i) for i in b]
print('Output :', find_maxwall(high))