import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from scipy.stats import linregress, t as student_t
import seaborn as sns
from pathlib import Path

sns.set_theme(style="darkgrid")

# Millikan's oil drop experiment
input_path = Path("C:\\Users\\Owner\\Desktop\\Code\\Second Year\\Labs\\Drops.csv")
raw_data = pd.read_csv(input_path, dtype=str)
q = raw_data.apply(pd.to_numeric, errors="coerce")

# --------------------------------------------------
# 1. Cluster the charge measurements into 3 groups
# --------------------------------------------------

kmeans = KMeans(n_clusters=3, random_state=42, n_init=20)

# KMeans expects a 2D array
labels = kmeans.fit_predict(q)

# Sort the clusters by their charge
centers = kmeans.cluster_centers_.flatten()
order = np.argsort(centers)

# Remap labels so that 0 = lowest charge, etc.
new_labels = np.zeros_like(labels)

for new_label, old_label in enumerate(order):
    new_labels[labels == old_label] = new_label

centers = np.sort(centers)

# --------------------------------------------------
# 2. Fit each horizontal line
# --------------------------------------------------

fit_values = []
fit_errors = []

for i in range(3):
    q_group = q[new_labels == i]
    n = len(q_group)

    # Best-fit horizontal line = weighted mean
    q_fit = np.mean(q_group)

    # Standard error of the mean
    q_error = np.std(q_group, ddof=1) / np.sqrt(n)

    fit_values.append(q_fit)
    fit_errors.append(q_error)

# --------------------------------------------------
# 3. Plot
# --------------------------------------------------


x = np.arange(len(q))
colors = ["#2878B5", "#F28E2B", "#5AA9E6"]

plt.figure(figsize=(10, 6))

for i in range(3):
    mask = new_labels == i

    plt.scatter(
        x[mask],
        q[mask],
        color=colors[i],
        label=f"Group {i+1}"
    )
    
    plt.errorbar(
        x[mask],
        q[mask],
        fmt='o',
        color=colors[i],
        alpha=0.5,
        capsize=3
    )

    plt.axhline(
        fit_values[i],
        color=colors[i],
        linestyle="--",
        label=f"Fit: {i+1} * {(fit_values[i] / (i+1) ):.3e} C"
    )

plt.xlabel("Oil drop number")
plt.ylabel("Charge q (C)")
plt.title("Millikan Oil Drop Experiment")
plt.legend()
plt.grid(alpha=0.3)

plt.show()

average = (centers[0]*16 + (centers[1]/2)*2 + (centers[2]/3)*2)/20
print(average)
print(centers)