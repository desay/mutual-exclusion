//
// Created by Helga on 2019-12-23.
//

#ifndef MUTUAL_EXCLUSION_QUEUE_H
#define MUTUAL_EXCLUSION_QUEUE_H


class Queue {

public:
    Queue();
    void enqueue (void *);
    void * dequeue ();
    bool empty ();


private:
    struct queue {
        void * obj;
        queue * next;
    };

    queue * head;
    queue * tail;
};


#endif //MUTUAL_EXCLUSION_QUEUE_H
