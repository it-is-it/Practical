#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class KS
{
private:
    float numbers[20];
    float D, tabulatedD;
    float Dplusmax, Dminusmax;
    float Dplus[20], Dminus[20];
    float ratio[20], ratiominus[20];
    int n;

public:
    // Function to get the random numbers
    void getdata()
    {
        cout << "How many numbers?: ";
        cin >> n;
        cout << "Enter " << n << " numbers:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    // Function to arrange numbers in increasing order
    void BubbleSort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (numbers[j] > numbers[j + 1])
                {
                    swap(numbers[j], numbers[j + 1]);
                }
            }
        }

        cout << "The numbers in ascending order are:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(2) << numbers[i] << " ";
        }
        cout << endl;
    }

    // Function to calculate D+, D-
    void calculate()
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            ratio[i] = static_cast<float>(j) / n;
            ratiominus[i] = static_cast<float>(i) / n;
            Dplus[i] = ratio[i] - numbers[i];
            Dminus[i] = numbers[i] - ratiominus[i];
        }
    }

    // Function to display results and find D
    void display()
    {
        cout << endl
             << setw(10) << "i";
        for (int i = 1; i <= n; i++)
        {
            cout << setw(10) << i;
        }
        cout << endl;

        cout << setw(10) << "R(i)";
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << fixed << setprecision(2) << numbers[i];
        }
        cout << endl;

        cout << setw(10) << "i/n";
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << setprecision(2) << ratio[i];
        }
        cout << endl;

        cout << setw(10) << "D+";
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << setprecision(2) << Dplus[i];
        }
        cout << endl;

        cout << setw(10) << "D-";
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << setprecision(2) << Dminus[i];
        }
        cout << endl;

        Dplusmax = Dplus[0];
        Dminusmax = Dminus[0];
        for (int i = 1; i < n; i++)
        {
            if (Dplus[i] > Dplusmax)
            {
                Dplusmax = Dplus[i];
            }
            if (Dminus[i] > Dminusmax)
            {
                Dminusmax = Dminus[i];
            }
        }

        cout << "D+ max: " << Dplusmax << endl;
        cout << "D- max: " << Dminusmax << endl;
        D = max(Dplusmax, Dminusmax);
        cout << "D = max(" << Dplusmax << ", " << Dminusmax << ") = " << D << endl;
    }

    // Function to accept the tabulated value and compare it with calculated D
    void conclusion()
    {
        cout << "Enter the tabulated value for D: ";
        cin >> tabulatedD;
        if (D < tabulatedD)
        {
            cout << "The test is accepted." << endl;
        }
        else
        {
            cout << "The test is rejected." << endl;
        }
    }
};

int main()
{
    KS ks1;           // Object of KS class
    ks1.getdata();    // Get the random numbers
    ks1.BubbleSort(); // Sort the numbers in ascending order
    ks1.calculate();  // Calculate D+ and D-
    ks1.display();    // Display the results
    ks1.conclusion(); // Compare with the tabulated value
    return 0;
}
