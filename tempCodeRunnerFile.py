import pandas as pd
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

# Load data from CSV file into a DataFrame
file_path = "synthetic_time_series.csv"  # Replace "your_file_path.csv" with the actual path to your CSV file
df = pd.read_csv(file_path)


# Function to perform OMP algorithm
def perform_omp(data, max_lag, sparsity):
    num_vars = data.shape[1]
    G = np.zeros((num_vars, num_vars))

    for effect in range(num_vars):
        x = np.array(data.iloc[max_lag:])
        y = np.array(data.iloc[max_lag - 1 : -1, effect])
        A = np.zeros((len(y), max_lag * num_vars))

        for i in range(max_lag):
            A[:, i * num_vars : (i + 1) * num_vars] = np.array(
                data.iloc[max_lag - 1 - i : -1 - i, :]
            )

        x_hat = np.zeros(max_lag * num_vars)
        support = set()

        for _ in range(sparsity):
            max_correlation = 0
            best_index = -1

            for j in range(max_lag * num_vars):
                if j not in support:
                    projection = np.dot(A[:, j], y)
                    correlation = np.abs(projection)

                    if correlation > max_correlation:
                        max_correlation = correlation
                        best_index = j

            support.add(best_index)
            x_hat[list(support)] = np.linalg.lstsq(A[:, list(support)], y, rcond=None)[
                0
            ]
            residual = y - np.dot(A[:, list(support)], x_hat[list(support)])
            y = residual

            if np.linalg.norm(residual) < 1e-5:
                break

        for cause in support:
            lag = cause // num_vars
            cause_idx = cause % num_vars
            G[cause_idx, effect] = 1

    return G


# Perform OMP algorithm
max_lag = 5
sparsity = 1
G = perform_omp(df, max_lag, sparsity)

# Draw the Granger graph
plt.figure(figsize=(10, 6))
G = nx.DiGraph(G)
labels = {i: col for i, col in enumerate(df.columns)}
pos = nx.spring_layout(G, seed=42)  # Positions for all nodes
nx.draw(
    G,
    pos,
    with_labels=True,
    labels=labels,
    node_size=2000,
    node_color="skyblue",
    font_size=12,
    font_weight="bold",
    arrowsize=20,
)
plt.title("Granger Causality Graph", fontsize=16)
plt.show()
