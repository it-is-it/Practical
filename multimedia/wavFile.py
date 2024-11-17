import wave


def get_wave_parameters(wav_file_path):
    with wave.open(wav_file_path, 'rb') as wav_file:
        num_channels = wav_file.getnchannels()  # Number of channels
        sampwidth = wav_file.getsampwidth()  # Sample width (bit depth)
        framerate = wav_file.getframerate()  # Sampling rate (samples per second)
        num_samples = wav_file.getnframes()  # Total number of samples

        print(f"Number of Channels: {num_channels}")
        print(f"Sample Width (Bit Depth): {sampwidth * 8} bits")
        print(f"Sampling Rate: {framerate} samples per second")
        print(f"Number of Samples: {num_samples}")


wav_file_path = r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\audio.wav"

get_wave_parameters(wav_file_path)
