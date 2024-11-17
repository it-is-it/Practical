import numpy as np
import matplotlib.pyplot as plt


def dct1d(x):
    N = len(x)
    X = np.zeros(N)
    for k in range(N):
        X[k] = np.sum(x * np.cos(np.pi / N * (np.arange(N) + 0.5) * k))
    return X


def idct1d(X):
    N = len(X)
    x = np.zeros(N)
    for n in range(N):
        x[n] = (2 / N) * np.sum(X * np.cos(np.pi / N * (n + 0.5) * np.arange(N)))
    return x


signal = np.array([1, 2, 3, 4, 5, 6, 7, 8], dtype=float)
dct_encoded = dct1d(signal)
decoded_signal = idct1d(dct_encoded)

plt.plot(signal, label='Original Signal')
plt.plot(decoded_signal, label='Decoded Signal', linestyle='--')
plt.legend()
plt.title('Original and Decoded Signals (DCT Encoding/Decoding)')
plt.savefig(
    r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\dct_signal_plot.png")
plt.close()

print("Original Signal:", signal)
print("DCT Encoded Signal:", dct_encoded)
print("Decoded Signal (IDCT):", decoded_signal)
