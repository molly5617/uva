import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from sklearn.linear_model import OrthogonalMatchingPursuit
from sklearn.datasets import make_regression

# 讀取CSV文件
synthetic_time_series = pd.read_csv(
    "synthetic_time_series.csv", dtype={"column_name": float}
)

syn_log = np.log(synthetic_time_series / synthetic_time_series.shift(1))[1:]
syn_log = syn_log.iloc[::-1]

T, p = syn_log.shape
L = 5

X = np.zeros((T - L, p * L))

for i in range(p):
    for j in range(L):
        X[:, L * i + j] = np.matrix(syn_log.iloc[:, i].shift(-(j + 1)).iloc[:-L])

y = syn_log.iloc[:-L]  # 最左邊那列


def omp_algorithm(data, x, s):
    data_normalized = np.linalg.norm(data, axis=0)  # 歐幾里得範數
    b = data / data_normalized

    # 初始化
    r = x
    lam = set()
    l = 1
    n = b.shape[1]  # b的行數
    c = np.zero(n)

    while l <= s:
        index = np.argmax(np.abs(b.T @ r))  # b_{sl}=argmax|b^T r_{l-1}|
        lam.add(index)  # lambda_l=lambda_{l-1} union {s_l}
        b_lambda = b[:, list(index)]
        c = (
            np.linalg.inv(b_lambda.T @ b_lambda) @ b_lambda.T @ x
        )  # c_{\lambda l}=(B_{\lambda l}^T B_{\lambda l})^{-1}B_{\lambda l}^T x
        coef[list(index_set)] = c
        r = x - b_lambda @ c
