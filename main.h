//
// Created by berta on 11-5-22.
//

#ifndef BYZANTINEAGREEMENT_MAIN_H
#define BYZANTINEAGREEMENT_MAIN_H

struct coin {
    int sender_id;
    int receiver_id;
    int coin_toss;
};

void fail_stop_protocol(int k);

#endif //BYZANTINEAGREEMENT_MAIN_H
