import matplotlib.pyplot as plt
import pandas as pd

data = {
    "N": [1e5, 1e6, 1e7, 1e8],
    "pi": [3.1426, 3.1419, 3.1417, 3.1415],
    "time": [0.05, 0.48, 4.6, 45.1]
}

df = pd.DataFrame(data)
plt.figure(figsize=(6,4))
plt.plot(df["N"], df["pi"], "o-", label="Estimation de π")
plt.axhline(3.1415926535, color="r", linestyle="--", label="Valeur réelle de π")
plt.xscale("log")
plt.xlabel("Nombre de tirages (N)")
plt.ylabel("Valeur estimée de π")
plt.title("Convergence de π (méthode de Monte Carlo)")
plt.savefig("convergence.png", dpi=300)
plt.legend()
plt.grid()
plt.show()
