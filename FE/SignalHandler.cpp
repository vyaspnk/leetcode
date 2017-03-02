#include <iostream>
using namespace std;
#include <unistd.h>
#include <signal.h>

void myHandler(int signalnum){
    cout << "OUCH!!!" << endl;
}

int main() {
    signal(SIGINT,myHandler);
    signal(SIGQUIT,myHandler);

    while(true) {
    	sleep(1);
        cout << "HAHA!!" << endl;
    }
    return 0;
}
