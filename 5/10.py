import numpy as np
import math


def calculate_put_price(S, X, r, s, T, H, n):
    dt = T / n
    u = np.exp((r - 0.5 * (s**2)) * dt + s * math.sqrt(2 * dt))
    d = np.exp((r - 0.5 * (s**2)) * dt - s * math.sqrt(2 * dt))
    m = 1
    p = (np.exp(r * dt) - d) / (u - d)
    q = 1 - p
    stock_price_tree = np.zeros([n + 1, n + 1])
    barrier_put_price_tree = np.zeros([n + 1, n + 1])
    for i in range(n + 1):
        for j in range(i + 1):
            stock_price_tree[j, i] = S * (d**j) * (u ** (i - j))
            if stock_price_tree[j, i] > H:
                barrier_put_price_tree[j, i] = 0.0
            else:
                barrier_put_price_tree[j, i] = max(X - stock_price_tree[j, i], 0)
    for i in np.arange(n - 1, -1, -1):
        for j in np.arange(0, i + 1):
            barrier_put_price_tree[j, i] = np.exp(-r * dt) * (
                p * barrier_put_price_tree[j, i + 1]
                + q * barrier_put_price_tree[j + 1, i + 1]
            )
    return barrier_put_price_tree[0, 0]


S = 100
X = 110
r = 0.03
s = 0.3
T = 60 / 365
H = 120
n = 100

put_price = calculate_put_price(S, X, r, s, T, H, n)
print("%.6f" % put_price)
