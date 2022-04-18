#ifndef SEQ
#define SEQ

using namespace std;

template <typename T>
void for_sequentiel(int min, int max, T traitement) {
    for(int i = min; i < max; i++) {
        traitement(i);
    }
}

template <int NB, typename T>
void for_parallele(int min, int max, T traitement) {
    thread t[NB];

    for(int i = 0; i < NB; i++) {
        t[i] = thread([&](int i) {
            for_sequentiel(i * (max / NB), (i + 1) * (max / NB), traitement);
        }
        ,i);
    }

    for (int i = 0; i < NB; i++) {
        t[i].join();
    }
}




#endif