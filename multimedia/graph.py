import matplotlib.pyplot as plt

# Data for the chart
years = ['2022-23', '2023-24', '2024-25 (1st Month)', '2024-25 (Projected)']
total_cases = [9013, 19730, 2100]
fraud_cases = [1835, 4112, None]  # Fraud cases for 2024-25 are not available

# Projected values for 2024-25 (12 times the first month's data)
predicted_total_cases = total_cases[-1] * 12
predicted_fraud_cases = 1835 / 9013 * predicted_total_cases  # Using the ratio of fraud to total in 2022-23

total_cases.append(predicted_total_cases)
fraud_cases.append(predicted_fraud_cases)

# Create a bar chart
x = range(len(years))
width = 0.4

plt.figure(figsize=(12, 6))
plt.bar(x, total_cases, width, label='Total Cases', color='steelblue')
plt.bar(x, [case if case else 0 for case in fraud_cases], width * 0.6, label='Online Fraud Cases', color='orange')

# Annotating the bars
for i in range(len(years)):
    plt.text(i, total_cases[i] + 500, f"{int(total_cases[i]):,}", ha='center', fontsize=10, color='black')
    if fraud_cases[i]:
        plt.text(i, fraud_cases[i] + 500, f"{int(fraud_cases[i]):,}", ha='center', fontsize=10, color='darkorange')

# Labels and title
plt.xlabel("Fiscal Year", fontsize=12)
plt.ylabel("Number of Cases", fontsize=12)
plt.title("Cybercrime Cases in Nepal (2022-25 with Projection)", fontsize=14)
plt.xticks(x, years)
plt.legend()

plt.tight_layout()
plt.show()
