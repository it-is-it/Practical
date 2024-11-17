import numpy as np
import wave
import struct

frequency = 4400
amplitude = 400
sampling_rate = 44100
duration = 1
phase = 0

t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)
samples = amplitude * np.sin(2 * np.pi * frequency * t + phase)
samples = np.int16(samples)

wav_file_path = r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\sine_wave_4400hz.wav"
with wave.open(wav_file_path, 'w') as wav_file:
    wav_file.setnchannels(1)
    wav_file.setsampwidth(2)
    wav_file.setframerate(sampling_rate)
    wav_file.writeframes(samples.tobytes())

print(f"Wave file saved at: {wav_file_path}")
