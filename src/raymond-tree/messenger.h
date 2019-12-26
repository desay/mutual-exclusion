//
// Created by Helga on 2019-12-26.
//

#ifndef MUTUAL_EXCLUSION_MESSENGER_H
#define MUTUAL_EXCLUSION_MESSENGER_H


#include "Request.h"

class Messenger {
public:
    Messenger(Simulator*);

    //send message to site
    void send (int, int, int, Request*);

private:
    Queue* timeline;
    int* weighted_delays;
    const int wd_size;

    Simulator* s;

    int compute_delivery_delay ();
};

#endif //MUTUAL_EXCLUSION_MESSENGER_H
