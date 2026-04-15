#include <iostream>
using namespace std;

const int MAX = 100;
class JobQueue {
    int front, rear;
    string jobs[MAX];
public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void addJob(string job) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1)
            front = 0;
        jobs[++rear] = job;
        cout << "Job '" << job << "' added to the queue.\n";
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is empty! No jobs to delete.\n";
            return;
        }
        cout << "Job '" << jobs[front] << "' completed and removed from queue.\n";
        front++;
    }

    void displayJobs() {
        if (isEmpty()) {
            cout << "No jobs in the queue.\n";
            return;
        }
        cout << "\nCurrent Jobs in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << " - " << jobs[i] << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string jobName;

    cout << "=== Job Queue Simulation ===\n";
    do {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> jobName;
                jq.addJob(jobName);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayJobs();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

  return 0;
}


