n = int(input())

while n > 0:
    s = str(input())
    ans = 0
    temp = 0

    for char in s:
        if char == "O":
            temp += 1
        else:
            temp = 0
        ans += temp

    print(ans)
    n -= 1
