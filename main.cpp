//
// Created by berta on 11-5-22.
//

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <utility>
#include <thread>
#include <vector>
#include <mutex>
#include <math.h>
extern "C" {
    #include <quantum.h>
}
#include <time.h>
#define N_PLAYERS 3

void fail_stop_protocol(int player_id) {
    std::mutex lock;
    std::vector<coin> coin_results;

    quantum_reg coin;
    int result;

    lock.lock();
    srand(time(0));

    coin = quantum_new_qureg(0, N_PLAYERS);
    for(int i = 0; i < N_PLAYERS; i++) {
        quantum_hadamard(i, &coin);
        result = quantum_bmeasure(i, &coin);

        printf("Player %i got %i for %i player\n", player_id, result, i);
        coin_results.push_back({player_id, i, result});
    }
    lock.unlock();


    /*quantum_reg leader;
    srand(time(0));

    long upper_bound = pow(N_PLAYERS, 3);
    leader = quantum_new_qureg(1, upper_bound);

    double exponent = pow(N_PLAYERS, (3/2));
    COMPLEX_FLOAT amplitude = sqrt(1.0/pow(N_PLAYERS, (3/2)));
    printf("Exp %f \n", exponent);
    leader.node->amplitude = amplitude;
    lock.lock();
    std::cout << "Amplitude: " << leader.node->amplitude << std::endl;

    for(int i = 0; i < N_PLAYERS; i++) {
        int result2 = quantum_bmeasure(i, &leader);
        printf("Player %i got leader %i for %i player\n", k, result2, i);
    }
    lock.unlock();
    */
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < N_PLAYERS; ++i) {
        threads.push_back(std::thread(fail_stop_protocol, i));
    }
    for(int i = 0; i < N_PLAYERS; ++i) {
        if(threads[i].joinable()) {
            threads[i].join();
        }
    }

    return 0;
}
