// Algorithm
// Step1 −  Find the maximum deadline value from the input set
// of jobs.
// Step2 −  Once, the deadline is decided, arrange the jobs
// in descending order of their profits.
// Step3 −  Selects the jobs with highest profits, their time
// periods not exceeding the maximum deadline.
// Step4 −  The selected set of jobs are the output.

#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;      // Job Id
    int deadLine; // Deadline of job
    int profit;   // Profit if job is done before or on deadline
};

// Comparator function to sort jobs according to their profit
bool comp(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}

// Function to find the minimum of two integers
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    Job jobs[] = {{'a', 2, 100}, {'b', 2, 20}, {'c', 1, 40}, {'d', 3, 35}, {'e', 1, 25}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    cout << "Following is the maximum profit sequence of jobs:\n";

    // Sort jobs according to their profit
    sort(jobs, jobs + n, comp);

    int jobSeq[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = min(n, jobs[i].deadLine) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                jobSeq[j] = i;  // Add this job to job sequence
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the job sequence
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << jobs[jobSeq[i]].id << " ";
        }
    }

    return 0;
}
