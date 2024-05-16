#include <iostream>
#include <vector>

using namespace std;
struct Process {
    int process_id;
    int burst_time;
};
void fcfs(vector<Process>& processes) {
    int n = processes.size();
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    cout << "Process ID\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    int current_time = 0;
    for (int i = 0; i < n; ++i) {
        int waiting_time = max(0, current_time - processes[i].burst_time);
        int turnaround_time = waiting_time + processes[i].burst_time;
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
        cout << processes[i].process_id << "\t\t" << processes[i].burst_time << "\t\t" << waiting_time << "\t\t" << turnaround_time << endl;
        current_time += processes[i].burst_time;
    }
    cout << "Average Waiting Time: " << (double)total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << (double)total_turnaround_time / n << endl;
}

int main() {
    
    vector<Process> processes = {
        {1, 6},  
        {2, 8},
        {3, 7},
        {4, 3},
    };
    fcfs(processes);
    return 0;
}
