import numpy as np
import matplotlib.pyplot as plt

frequency = 3  # Frequency of the sine wave (Hz)
amplitude = 1  # Amplitude of the sine wave
phase = 0  # Phase shift (radians)
sampling_rate = 2  # Sampling rate (samples per second)
start_time = 0  # Start time (seconds)
end_time = 10  # End time (seconds)

time = np.arange(start_time, end_time, 1/sampling_rate)
samples = amplitude * np.sin(2 * np.pi * frequency * time + phase)

plt.stem(time, samples, basefmt=" ")
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.title('Sine Wave Samples at 3Hz with 2Hz Sampling Rate')
plt.grid(True)

plt.savefig(r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\sineWave2.png")
plt.close()
