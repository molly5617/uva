import numpy as np


def trinomial_tree_up_and_out_put(S, X, r, s, T, H, n):
    # p244

    delta_t = T / n
    h = np.floor(np.log(H / S) / (s * np.sqrt(delta_t)))

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
        next_times = [times + 1 for times in times[i]] + [
            times[i][-1],
            times[i][-1] - 1,
        ]
        now_prices.append(next_prices)
        times.append(next_times)

    # 計算到期時的期權價值
    C = [max(0, X - price) if price < H else 0 for price in now_prices[n]]

    # 從到期時刻向後遞推計算期權價值
    for j in range(n - 1, -1, -1):
        prev_C = []
        for i in range(len(C) - 2):
            if times[j][i] < h:
                payoff = (pu * C[i] + pm * C[i + 1] + pd * C[i + 2]) / np.exp(
                    r * delta_t
                )
            else:  # 如果觸及障礙，期權價值為0
                payoff = 0
            prev_C.append(payoff)
        C = prev_C

    return C[0]


if __name__ == "__main__":
    S = 100
    X = 110
    r = 0.03
    s = 0.3
    T = 60 / 365
    H = 120
    n = 100

    price = trinomial_tree_up_and_out_put(S, X, r, s, T, H, n)
    print("{0:.6f}".format(price))
