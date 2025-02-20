#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct;    
    int tat;     
    int wt;       
};

bool compareBT(Process a, Process b) {
    return a.bt < b.bt;
}

bool compareAT(Process a, Process b) {
    return a.at < b.at;
}


int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter Burst Time and Arrival Time for Processes: \n";
    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << ": ";
        cin >> p[i].bt >> p[i].at;
    }

    // Sort processes by arrival time
    sort(p, p + n, compareAT);

    int time = 0; // Current time tracker
    int completed = 0; // Number of completed processes
    bool visited[n] = {false};

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= time && p[i].bt < minBT) {
                minBT = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) {
            time++; // No process is ready, so increase time
        } else {
            // Process execution
            p[idx].ct = time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            visited[idx] = true;
            time = p[idx].ct;
            completed++;
        }
    }

    double totalWT = 0, totalTAT = 0;
    cout << "\nProcess  AT  BT  CT  TAT WT\n";
    for (int i = 0; i < n; i++) {
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "\nAverage Turnaround Time: " << (totalTAT / n);
    cout << "\nAverage Waiting Time: " << (totalWT / n) << "\n";
    return 0;
}