time = 1

while True:
    n, q = map(int, input().split())
    if n == 0 and q == 0:
        break
    v = [int(input()) for _ in range(n)]
    v.sort()
    print(f'CASE# {time}:')
    for _ in range(q):
        k = int(input())
        for i in range(n):
            if v[i] == k:
                print(f'{k} found at {i + 1}\n')
                break
        else:
            print(f'{k} not found\n')
       
        

    time += 1
