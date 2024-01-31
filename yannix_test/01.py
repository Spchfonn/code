def fibo(n) :
    if(n==1) : return 1
    elif(n==2) : return 2
    return fibo(n-1) + fibo(n-2)

n = int(input('Input : n = '))
print('Output : %d' %fibo(n))
