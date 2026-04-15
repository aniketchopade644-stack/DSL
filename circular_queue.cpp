#include <iostream>
using namespace std;

#define MAX 5  // Maximum print jobs allowed in the system

class CircularQueue {
    string jobs[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }
void enqueue(string job) {
        if (isFull()) {
            cout << "Printer queue is full! Cannot add job '" << job << "'.\n";
            return;
        }
        if (isEmpty())
            front = 0;

        rear = (rear + 1) % MAX;
        jobs[rear] = job;
        cout << "Job '" << job << "' added to printer queue.\n";
    }
void dequeue() {
        if (isEmpty()) {
            cout << "Printer queue is empty! No job to process.\n";
            return;
        }
        cout << "Processing job '" << jobs[front] << "' and removing from queue.\n";

        if (front == rear) {
            // Only one job was in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void displayFront() {
        if (isEmpty()) {
            cout << "Printer queue is empty.\n";
        } else {
            cout << "Front job: '" << jobs[front] << "'\n";
        }
    }

    int printJobCount() {
        if (isEmpty()) return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return MAX - (front - rear - 1);
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Printer queue is empty.\n";
            return;
        }
        cout << "Current Jobs in Queue: ";
        int i = front;
        while (true) {
            cout << jobs[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main() {
    CircularQueue printerQueue;
    int choice;
    string job;

    cout << "=== Circular Printer Queue Simulation ===\n";

    do {
        cout << "\n1. Add Job (Enqueue)\n2. Process Job (Dequeue)\n3. Check Front Job\n";
        cout << "4. Check if Queue is Empty\n5. Check if Queue is Full\n";
        cout << "6. Print Job Count\n7. Display Queue\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin >> job;
                printerQueue.enqueue(job);
                break;
            case 2:
                printerQueue.dequeue();
                break;
            case 3:
                printerQueue.displayFront();
                break;
            case 4:
                if (printerQueue.isEmpty()) cout << "Queue is empty.\n";
                else cout << "Queue is not empty.\n";
                break;
            case 5:
                if (printerQueue.isFull()) cout << "Queue is full.\n";
                else cout << "Queue is not full.\n";
                break;
            case 6:
                cout << "Current number of jobs: " << printerQueue.printJobCount() << endl;
                break;
            case 7:
                printerQueue.displayQueue();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
