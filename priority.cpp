#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int priority;
};

bool compare(Process a, Process b) {
    return a.priority > b.priority;
}

void priorityScheduling(Process processes[], int n) {
    sort(processes, processes + n, compare);

    int waitingTime[n], turnaroundTime[n];
    waitingTime[0] = 0;
    
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    cout << "\nPriority Scheduling Result:\n";
    cout << "PID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t"
             << processes[i].priority << "\t"
             << processes[i].burstTime << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process processes[n];
    cout << "Enter Process ID, Burst Time, and Priority:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].burstTime >> processes[i].priority;
    }

    priorityScheduling(processes, n);
    return 0;
}