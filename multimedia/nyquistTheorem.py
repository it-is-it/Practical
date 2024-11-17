import numpy as np
import matplotlib.pyplot as plt

frequency = 3  # Frequency of the sine wave (Hz)
amplitude = 1  # Amplitude of the sine wave
phase = 0  # Phase shift (radians)
sampling_rate = 6  # Nyquist sampling rate (2 * frequency)
start_time = 0  # Start time (seconds)
end_time = 10  # End time (seconds)

time = np.arange(start_time, end_time, 1/sampling_rate)
samples = amplitude * np.sin(2 * np.pi * frequency * time + phase)

plt.plot(time, samples, label='Sine Wave')
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.title('Sine Wave at 3Hz with Nyquist Sampling Rate (6Hz)')
plt.grid(True)
plt.legend()

plt.savefig(
    r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\Nyquist_theorem.png")
plt.close()
