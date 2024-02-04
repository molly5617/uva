def count_zeros(n):
    count = 0
    while n % 5 == 0:
        count += 1
        n //= 5
    return count

low, high, pre = 0, 0, 600
dp = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 1}

for i in range(6, 9000000000000000000):
    num = count_zeros(i)
    dp[i] = dp[i - 1] + num

while True:
    low, high = map(int, input().split())
    if low == 0:
        break

    ans = set()
    if low > pre:
        for i in range(pre + 1, high + 1):
            num = count_zeros(i)
            dp[i] = dp[i - 1] + num

    pre = high
    for i in range(low, high + 1):
        if dp[i] != 0:
            ans.add(dp[i])
        else:
            num = count_zeros(i)
            dp[i] = dp[i - 1] + num
            ans.add(dp[i])

    print(len(ans))
