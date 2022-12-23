s = input()
b = s[1:-1].split(',')
a = []
for x in b:
    a.append(int(x))
s = 0

for i in range(len(a)):
    s += a[i]
if (s % 2 != 0):
    print('False')
    exit(0)
s = s // 2
dp = [0] * (s + 1)
dp[0] = 1
for i in range(len(a)):
    for j in reversed(range(a[i], s + 1)):
        dp[j] |= dp[j - a[i]]
if (dp[s] == 1):
    print('True')
else:
    print('False')
