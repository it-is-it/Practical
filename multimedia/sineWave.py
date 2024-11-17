import numpy as np
import matplotlib.pyplot as plt

frequency = 3  # in Hz
amplitude = 1  # amplitude of the sine wave
phase = 0  # phase shift in radians
time_interval = 0.3  # time interval between samples
num_samples = 10  # number of samples to generate

time = np.linspace(0, (num_samples - 1) * time_interval, num_samples)
samples = amplitude * np.sin(2 * np.pi * frequency * time + phase)

plt.plot(time, samples, 'o-', label='Sine Wave Samples')
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.title('Sine Wave Samples at 3Hz')

plt.legend()
plt.grid(True)

plt.savefig(r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\sineWave.png")
plt.close()
