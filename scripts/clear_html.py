#!/usr/bin/env python3

import pandas as pd

table = pd.read_html("grammar/princeton_output.html")[0]
table.index = table["Unnamed: 0"]
table.drop("Unnamed: 0", inplace=True, axis=1)
table.dropna(axis=0, how="all", inplace=True)

num_participants = 4
N = len(table)
block_size = N // 4

num_participants = 4
N = len(table)
block_size = N // num_participants

for i, (idx, info) in enumerate(table.iterrows()):
    print(i, idx)
    for col, cell in info.items():
        if not type(cell) is float:
            print(col, " => ", cell)

    print("================================")
