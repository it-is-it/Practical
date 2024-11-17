import matplotlib.pyplot as plt


def lzw_encode(input_data):
    dictionary, next_code, current_string, encoded_output = {
        chr(i): i for i in range(256)}, 256, "", []
    for symbol in input_data:
        temp_string = current_string + symbol
        if temp_string in dictionary:
            current_string = temp_string
        else:
            encoded_output.append(dictionary[current_string])
            dictionary[temp_string] = next_code
            next_code += 1
            current_string = symbol
    if current_string:
        encoded_output.append(dictionary[current_string])
    return encoded_output


def lzw_decode(encoded_data):
    dictionary, next_code, current_code, decoded_output = {
        i: chr(i) for i in range(256)}, 256, encoded_data[0], [chr(encoded_data[0])]
    current_string = chr(current_code)
    for code in encoded_data[1:]:
        entry = dictionary.get(code, current_string + current_string[0])
        decoded_output.append(entry)
        dictionary[next_code] = current_string + entry[0]
        next_code += 1
        current_string = entry
    return "".join(decoded_output)


input_data = "ABABABABA"
encoded_data = lzw_encode(input_data)
decoded_data = lzw_decode(encoded_data)

print("Original Data:", input_data)
print("Encoded Data:", encoded_data)
print("Decoded Data:", decoded_data)

plt.figure(figsize=(10, 4))
plt.subplot(1, 2, 1)
plt.plot(list(input_data), color='blue', marker='o')
plt.subplot(1, 2, 2)
plt.plot(list(decoded_data), color='red', marker='x')
plt.savefig(r"C:\Users\ishwo\Desktop\it-is-it\practical\multimedia\lzw_plot.png")
plt.close()
