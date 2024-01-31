n = int(input('Input 1 : '))
a = input('Input 2 : ')
b = a.split()
high = [int(i) for i in b]
x = (n + sum(high)) / len(high)
for i in high:
    if(i>x) : high.remove(i)
ans = ((n + sum(high)) / len(high)) - min(high)
print('Output : %.2f' %ans)