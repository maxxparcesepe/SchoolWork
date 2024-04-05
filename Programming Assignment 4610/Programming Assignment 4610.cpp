#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Process {
public:
    //public variables 
    string name;
    vector<int> burst_times;
    vector<int> io_times;
    int current_burst;
    int waiting_time;
    int turnaround_time;
    int response_time;


    //Function simulates a process. Takes a string n and a constant vector int called bursts.
    Process(string n, const vector<int>& bursts) : name(n), burst_times(bursts)//renames the public variables to n and bursts
    {
        for (int i = 1; i < bursts.size(); i += 2)//for loop increments i by 2 so that it goes by odd numbers
        {
            io_times.push_back(bursts[i]);//collects the items at odd indices and puts them in the vector io_times
        }

        //initialization of public variables
        current_burst = 0;
        waiting_time = 0;
        turnaround_time = 0;
        response_time = -1;//response time initialized to -1 to show that no processes have been created in base state
    }
};

class Queue {
public:
    //public variables
    string name;
    int time_quantum;
    queue<Process> processes;

    Queue(string n, int tq = 0) : name(n), time_quantum(tq) {}//changing public variable names to n and tq for name and time quantum

    //a void function for enqueue
    void enqueue(Process process)
    {
        processes.push(process);//pushes a process to the back of the queue 
    }

    //process function for dequeue
    Process dequeue() {
        if (!processes.empty())//true if queue is not empty, false if it is 
        {
            Process p = processes.front();//move process to front of queue 
            processes.pop();//pop the front element and move the remaining elements forward 
            return p;//return the process 
        }
        //If the queue is empty (the if condition is false), 
        //this line returns a default-constructed Process object with an empty name and an empty vector of burst times.
        return Process("", {});

    }
    


    bool isEmpty() {
        return processes.empty();
    }
};

void fcfs(vector<Process>& processes, Queue& queue) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < processes.size()) {
        // Check if any processes have arrived at the current time and enqueue them
        for (Process& p : processes) {
            if (p.current_burst == 0 && p.burst_times.size() > 0)//check to see that the current burst is zero and burst time size is a value 
            {
                p.response_time = currentTime;
                queue.enqueue(p);
            }
        }

        if (!queue.isEmpty()) {
            // Dequeue the process at the front of the queue
            Process p = queue.dequeue();

            // Execute the process for the specified burst time
            int burstTime = p.burst_times[p.current_burst];
            currentTime += burstTime;
            p.current_burst++;

            // Update statistics
            p.turnaround_time += currentTime;
            p.waiting_time += currentTime - p.response_time;

            // Check if the process has completed all its bursts
            if (p.current_burst >= p.burst_times.size()) {
                completedProcesses++;
            }
            else {
                // Enqueue the process again for its next burst
                queue.enqueue(p);
            }
        }
        else {
            currentTime++; // No process to execute, move time forward
        }
    }
}



void sjf(vector<Process>& processes) {
    // Implement SJF scheduling here
}

void mlfq(vector<Process>& processes, Queue& queue1, Queue& queue2, Queue& queue3) {
    // Implement MLFQ scheduling here
}

//MAIN ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    //Vector arrays to be tested
    vector<Process> processes = {
        Process("P1", {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4}),
        Process("P2", {4, 48, 5, 44, 7, 42, 12, 37, 9, 76, 4, 41, 9, 31, 7, 43, 8}),
        Process("P3", {8, 33, 12, 41, 18, 65, 14, 21, 4, 61, 15, 18, 14, 26, 5, 31, 6}),
        Process("P4", {3, 35, 4, 41, 5, 45, 3, 51, 4, 61, 5, 54, 6, 82, 5, 77, 3}),
        Process("P5", {16, 24, 17, 21, 5, 36, 16, 26, 7, 31, 13, 28, 11, 21, 6, 13, 3, 11, 4}),
        Process("P6", {11, 22, 4, 8, 5, 10, 6, 12, 7, 14, 9, 18, 12, 24, 15, 30, 8}),
        Process("P7", {14, 46, 17, 41, 11, 42, 15, 21, 4, 32, 7, 19, 16, 33, 10}),
        Process("P8", {4, 14, 5, 33, 6, 51, 14, 73, 16, 87, 6})
            };

    Queue queue1("Queue 1", 5);
    Queue queue2("Queue 2", 10);
    Queue queue3("Queue 3");

    fcfs(processes, queue1);
    sjf(processes);
    mlfq(processes, queue1, queue2, queue3);

    return 0;
}
