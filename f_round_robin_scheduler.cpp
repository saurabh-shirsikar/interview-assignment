#include <iostream>
#include <queue>
#include <vector>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void roundRobin(std::vector<Process>& processes, int timeQuantum) {
    std::queue<Process> q;
    for (auto& p : processes) q.push(p);
    int time = 0;
    std::cout << "Execution timeline:\n";
    while (!q.empty()) {
        Process p = q.front(); q.pop();
        int execTime = std::min(timeQuantum, p.remainingTime);
        std::cout << "Time " << time << " -> " << time + execTime << ": Process P" << p.id << "\n";
        time += execTime;
        p.remainingTime -= execTime;
        if (p.remainingTime > 0) q.push(p);
    }
}

int main() {
    std::vector<Process> processes = {{1, 5, 5}, {2, 3, 3}, {3, 6, 6}};
    int timeQuantum = 2;
    roundRobin(processes, timeQuantum);
    return 0;
}
