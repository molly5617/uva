import numpy as np
import sys


def trinomial_tree_up_and_out_put(S, X, r, s, T, H, n):
    delta_t = T / n
    h = int(np.floor(np.log(S / H) / (s * np.sqrt(delta_t))))
    if h < 1 or h >= n:  # 允许 h 等于 n
        return "failure"
    lam = np.log(S / H) / (h * s * np.sqrt(delta_t))
    pu = 1 / (2 * lam**2) + (r - s**2 / 2) * np.sqrt(delta_t) / (2 * lam * s)
    pd = 1 / (2 * lam**2) - (r - s**2 / 2) * np.sqrt(delta_t) / (2 * lam * s)
    pm = 1 - pu - pd
    u = np.exp(lam * s * np.sqrt(delta_t))
    d = 1 / u
    C = np.zeros(2 * n + 1)
    for i in range(2 * n + 1):
        C[i] = max(0, X - S * u ** (n - i))
    for i in range(n + h, 2 * n + 1):
        C[i] = 0
    for j in range(n - 1, -1, -1):
        for i in range(2 * j + 1):
            C[i] = pu * C[i] + pm * C[i + 1] + pd * C[i + 2]
            if i >= j + h:
                C[i] = 0
    return C[0] / np.exp(r * T)


if __name__ == "__main__":
    S = float(sys.argv[1])
    X = float(sys.argv[2])
    r = float(sys.argv[3])
    s = float(sys.argv[4])
    T = int(sys.argv[5]) / 365
    H = float(sys.argv[6])
    n = int(sys.argv[7])

    price = trinomial_tree_up_and_out_put(S, X, r, s, T, H, n)
    print(price)
