#include <iostream>
#include <mutex>
#include "nombre.hpp"

using namespace std;

mutex m;

void printTruc(int i) {
    m.lock();
    cout << "Pouet " << i << endl;
    m.unlock();
}

int main() {
    // Version avec fonction
    thread t[4];

    for(int i = 0; i < 4; i++) {
        t[i] = thread(printTruc, i);
    }

    for(int i = 0; i < 4; i++) {
        t[i].join();
    }

    // Version avec lambda
    thread t2[4];

    for(int i = 0; i < 4; i++) {
        t2[i] = thread(
            [=] () {
                cout << "Pouetv2 " << i << endl;
            }
        );
    }

    for(int i = 0; i < 4; i++) {
        t2[i].join();
    }

}

