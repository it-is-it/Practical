import matplotlib.pyplot as plt


def run_length_encoding(input_data):
    encoding, i = [], 0
    while i < len(input_data):
        count = 1
        while i + 1 < len(input_data) and input_data[i] == input_data[i + 1]:
            i += 1
            count += 1
        encoding.append((input_data[i], count))
        i += 1
    return encoding


def run_length_decoding(encoded_data):
    return [element * count for element, count in encoded_data]


input_data = "AAAABBBCCDAA"
encoded_data = run_length_encoding(input_data)
decoded_data = run_length_decoding(encoded_data)

print("Original Data:", input_data)
print("Encoded Data:", encoded_data)
print("Decoded Data:", "".join(decoded_data))

plt.figure(figsize=(10, 4))
plt.subplot(1, 2, 1)
plt.plot(list(input_data), color='blue', marker='o')
plt.subplot(1, 2, 2)
plt.plot(list("".join(decoded_data)), color='red', marker='x')
plt.savefig(r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\rle_plot.png")
plt.close()
