#include <iostream>
#include <queue>
using namespace std;

void roundRobinScheduling(int processes[], int n, int burstTime[], int timeQuantum) {
    int waitingTime[n] = {0}, turnaroundTime[n] = {0};
    int remainingTime[n];
    
    for (int i = 0; i < n; i++)
        remainingTime[i] = burstTime[i];
    
    queue<int> processQueue;
    for (int i = 0; i < n; i++)
        processQueue.push(i);
    
    int currentTime = 0;
    while (!processQueue.empty()) {
        int i = processQueue.front();
        processQueue.pop();
        
        if (remainingTime[i] > timeQuantum) {
            currentTime += timeQuantum;
            remainingTime[i] -= timeQuantum;
            processQueue.push(i);
        } else {
            currentTime += remainingTime[i];
            waitingTime[i] = currentTime - burstTime[i];
            remainingTime[i] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "P" << processes[i] << "\t " << burstTime[i] << "\t\t "
             << waitingTime[i] << "\t\t " << turnaroundTime[i] << endl;
}

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    
    int processes[n], burstTime[n];
    cout << "Enter burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> burstTime[i];
    }
    
    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;
    
    roundRobinScheduling(processes, n, burstTime, timeQuantum);
    return 0;
}
