#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 20

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;

pthread_mutex_t myMutex;

void * vCount (void *args) {
    ifstream inFile;
    string *p = (string *)args;
    string file = *p;
    delete p;
    pthread_mutex_lock(&myMutex);
    inFile.open(file.c_str());

    if (!inFile){
        cout << "Unable to open " << file << endl;
        exit(1);
    }
    char vw;
    while (inFile >> noskipws >> vw){
        if (vw == 'a' || vw == 'A')
            a++;
        else if (vw == 'b' || vw == 'B')
            b++;
        else if (vw == 'c' || vw == 'C')
            c++;
        else if (vw == 'd' || vw == 'D')
            d++;
        else if (vw == 'e' || vw == 'E')
            e++;
    }

    inFile.close();
    pthread_mutex_unlock(&myMutex);
    pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    pthread_t thread[NUM_THREADS];
    stringstream fileName;
    string *str_p;
    str_p = new string;
    pthread_mutex_init(&myMutex, 0);

    for (int n = 0; n < NUM_THREADS; n++){

        str_p = new string(fileName.str());
        if(pthread_create(&thread[n], NULL, vCount,
                          (void *)str_p)){
            cout << "Error with thread creation" << endl;
            return -1;
        }
        fileName.str("");
        fileName.clear();
    }

    for (int n = 0; n < NUM_THREADS; n++){

        if(pthread_join(thread[n], NULL)){
            cout << "Error joining thread" << endl;
            return -1;
        }

    }
    
    pthread_mutex_destroy(&myMutex);
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << "D: " << d << endl;
    cout << "E: " << e << endl;
    return 0;
}
