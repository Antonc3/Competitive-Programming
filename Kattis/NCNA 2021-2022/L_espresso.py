n, m = map(int, input().split())

res, full = 0, m
for i in range(n):
    s = input()
    val = int(s[0])
    if(len(s) == 2):
        val += 1
    if full >= val:
        full -= val
    else:
        full = m - val
        res += 1
print(res)