#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include <mutex>
#include <string>
#include <thread>
#include <deque>

using namespace std;

struct files {
    mutex m;
    deque<string> filenames;
};

struct counts {
    mutex m;
    deque<int> counts;
    deque<thread::id> who;
};

class functions {
public:
    static void map(files *fq, counts *cq, const string &needle);

    static void reduce(counts *cq);
};

#endif