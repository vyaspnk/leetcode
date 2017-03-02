#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

char** getCommandLine();
void freeArgs(char**);

int main() {
    while (true) {
        char** args = getCommandLine();
        pid_t pid = fork();
        if (pid < 0) {
            cerr << "simpleShell: could not fork new process\n";
            exit(1);
        }
        else if (pid == 0) { // child
            execvp(args[0], args);
            cerr << "simpleShell: exec failed\n";
        }
        else { // parent
            int status;
            waitpid(pid, &status, 0);
        }
        freeArgs(args);
    }
}

char** getCommandLine() {
    cout << "\n:-) ";
    string line;
    getline(cin, line);
    istrstream is(line.c_str());
    string x;
    vector<string> vs;
    while (is >> x)
        vs.push_back(x);
    int argc = vs.size();
    char** args = new char*[argc+1];
    for (int i = 0; i < argc; ++i) {
        args[i] = new char[vs[i].length() + 1];
        strcpy(args[i], vs[i].c_str());
    }
    args[argc] = NULL;
    return args;
}


void freeArgs(char** args) {
    if (args) 
        for (int i = 0; args[i]; i++)
            delete [] args[i];
    delete [] args;
}
