//
// Created by Helga on 2019-12-26.
//

#ifndef MUTUAL_EXCLUSION_REQUEST_H
#define MUTUAL_EXCLUSION_REQUEST_H


class Request {

public:
    Request(int id);
    virtual ~Request();

    int num_messages;		// keep track of number of messages per request
    int site_id;

};


#endif //MUTUAL_EXCLUSION_REQUEST_H
