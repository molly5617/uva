import sys
import numpy as np


def trinomial_tree_up_and_out_put(S, X, r, s, T, H, n):
    delta_t = T / n
    h = np.log(H / S) // (s * np.sqrt(delta_t))

    lam = np.log(H / S) / (h * s * np.sqrt(delta_t))
    pu = 1 / (2 * lam**2) + (r - s**2 / 2) * np.sqrt(delta_t) / (2 * lam * s)
    pd = 1 / (2 * lam**2) - (r - s**2 / 2) * np.sqrt(delta_t) / (2 * lam * s)
    pm = 1 - pu - pd
    u = np.exp(lam * s * np.sqrt(delta_t))
    d = 1 / u
    now_prices = [[S]]
    times = [[0]]

    for i in range(n):
        next_prices = [price * u for price in now_prices[i]] + [
            now_prices[i][-1],
            now_prices[i][-1] * d,
        ]
        next_up_times = [times + 1 for times in times[i]] + [
            times[i][-1],
            times[i][-1] - 1,
        ]
        now_prices.append(next_prices)
        times.append(next_up_times)

    C = [max(0, X - price) if price < H else 0 for price in now_prices[n]]

    for i in range(n - 1, -1, -1):
        C = [
            (
                (pu * C[payoff_i] + pm * C[payoff_i + 1] + pd * C[payoff_i + 2])
                / np.exp(r * delta_t)
                if times[i][payoff_i] < h
                else 0
            )
            for payoff_i in range(len(C) - 2)
        ]
    return C[0]


if __name__ == "__main__":
    S = float(sys.argv[1])
    X = float(sys.argv[2])
    r = float(sys.argv[3])
    s = float(sys.argv[4])
    T = int(sys.argv[5]) / 365
    H = float(sys.argv[6])
    n = int(sys.argv[7])

    price = trinomial_tree_up_and_out_put(S, X, r, s, T, H, n)
    print("{0:.6f}".format(price))
