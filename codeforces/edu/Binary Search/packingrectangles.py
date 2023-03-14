from sys import stdin, stdout
import math
[n,m,c] = [int(x) for x in stdin.readline().split()]

l = 0
r = 1e18
b = r
while l <= r:
    mid = math.floor((l+r)/2)
    if math.floor(mid/n)*math.floor(mid/m) >= c:
        b = mid
        r = mid-1
    else:
        l = mid+1
print(b)
