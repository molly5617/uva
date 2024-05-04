import numpy as np
import pandas as pd
from sklearn.linear_model import orthogonal_mp
import matplotlib.pyplot as plt
import networkx as nx

# 讀取CSV數據
data = pd.read_csv("synthetic_time_series.csv")

# 設定滯後和稀疏度
L = 5
s = 1


# 定義OMP函數
def omp_granger(data, L, s):
    n, m = data.shape
    granger_graph = np.zeros((m, m))

    for i in range(m):
        # 目標變量
        y = data.iloc[L:, i].values

        # 預測變量與滯後
        X = np.column_stack(
            [
                data.iloc[L - lag : -lag, j].values
                for j in range(m)
                for lag in range(1, L + 1)
            ]
        )

        # 應用OMP
        coef = orthogonal_mp(X, y, n_nonzero_coefs=s)

        # 更新Granger圖
        for j in range(m):
            if np.any(coef[j * L : (j + 1) * L]):
                granger_graph[j, i] = 1

    return granger_graph


# 獲取Granger圖
granger_graph = omp_granger(data, L, s)

# 繪製Granger圖
G = nx.DiGraph(granger_graph)
plt.figure(figsize=(12, 8))
nx.draw_circular(
    G,
    with_labels=True,
    node_color="lightblue",
    node_size=2500,
    edge_color="grey",
    linewidths=1.5,
    font_size=15,
)
plt.title("Granger Causality Graph")
plt.show()
