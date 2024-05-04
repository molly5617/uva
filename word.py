import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import networkx as nx

# 讀取CSV文件
synthetic_time_series = pd.read_csv(
    "synthetic_time_series.csv", dtype={"column_name": float}
)

syn_log = np.log(synthetic_time_series / synthetic_time_series.shift(1))[1:]
syn_log = syn_log.iloc[::-1]
T, p = syn_log.shape
L = 5

X = np.zeros((T - L, p * L))
