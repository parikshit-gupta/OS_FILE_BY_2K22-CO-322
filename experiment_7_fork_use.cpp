#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Parent process: My PID is " << getpid() << endl; //process ID of parent

    pid_t pid = fork();

    if (pid < 0) {
        //if fork call returns negetive value then some error has occured
        cerr << "Error: Fork failed" << endl;
        return 1;
    } else if (pid == 0) {
        // if fork call returns 0 the child process is being executed
        // This code is executed by the child process
        cout << "Child process: My PID is " << getpid() << endl; // getpid() returns the process ID of the current process
        cout << "Child process: My parent's PID is " << getppid() << endl;
        cout << "Child process: Hello from the child!" << endl;
    } else {
        // If fork returns a positive value, then the value returned represents the PID of the child process
        // This code is executed by the parent process
        cout << "Parent process: I have a child with PID " << pid << endl;
        cout << "Parent process: Hello from the parent!" << endl;
    }

    return 0;
}
