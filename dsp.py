import pandas as pd

# Load the data
data = pd.read_csv("stock_price_globe.csv")

data["Log_Return"] = data.groupby("Symbol")["Adj Close"].transform(
    lambda x: pd.np.log(1 + x.diff() / x.shift(1))
)

taiwan_data = data[data["Symbol"] == "Taiwan"]


last_5_dates_taiwan = taiwan_data.tail(5)
print(last_5_dates_taiwan[["Symbol", "Date", "Log_Return"]].to_string(index=False))
