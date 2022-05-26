//
// Created by berta on 11-5-22.
//

#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <quantum.h>

void byzantine_protocol(int n) {
    /*quantum_reg secret;
    int result;

    srand(time(0));

    secret = quantum_new_qureg(0, 1);
    quantum_hadamard(0, &secret);
    result = quantum_bmeasure(0, &secret);

    printf("The Quantum RNG returned %i\n", result);*/
    std::cout << "created thread, " << n << std::endl;

    //toss coin to determine secret

    //broadcast result of toss to all players -- add it to linked list?

    //receive secrets

    //verify secrets
}
