#include <iostream>
using namespace std;

int factorsOfN(int N) {
        int end = N;
        int factors=2;
        for(int i = 2; i<= end-1; i++) {
            if(N%i==0){
                factors++;
                if(N != (i*i))
                    factors++;
            }
            end = end/i;
        }
        cout << "Factors of " << N << " = " << factors << endl;
        return factors;
}


int main(){
    for(int i = 2;i<=10;i++){
        factorsOfN(i);
    }
    return 0;
}