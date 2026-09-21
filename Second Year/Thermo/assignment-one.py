import math as m

p = 0.5
n = 100000
k = 50000
omega = m.factorial(n) / (m.factorial(n-k) * m.factorial(k))

print(omega * (p ^ k) * ((1 - p) ^ (n - k)))