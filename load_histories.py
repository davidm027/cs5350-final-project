"""
How to use this file:
1. Make sure you have the Pandas library installed
2. Assume your `.csv` files are in a single directory
3. When plotting: get a dataframe by calling `load_histories()` on the file in `results/` you want to plot, then use matplotlib to plot
"""

import pandas as pd

def load_histories(file, pattern):
    out = pd.read_csv(file)

    # Basic cleanup
    out.columns = [c.strip() for c in out.columns]
    # out["m"] = out["m"].astype(int)
    # out["n"] = out["n"].astype(int)
    # out["q"] = out["q"].astype(int)
    # out["P"] = out["P"].astype(int)
    # out["MM_ser_sec"] = out["MM_ser_sec"].astype(float)
    # out["MM_Par_sec"] = out["MM_Par_sec"].astype(float)
    # out["MM_1D_sec"] = out["MM_1D_sec"].astype(float)
    # out["MM_2D_sec"] = out["MM_2D_sec"].astype(float)

    # out = out.groupby(["experiment", "m", "n", "q", "P"], as_index=False)[
    #    ["MM_ser_s", "MM_par_s", "MM_1d_s", "MM_2d_s"]
    # ].mean()

    return out
