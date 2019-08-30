#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

void functions::map(files* fq, counts* cq, const string& needle){
    while (true) {
        string fname;

        // Get work
        {
            unique_lock<mutex> lck(fq->m);
            if (fq->filenames.size() > 0) {

                fname = fq->filenames.front();
                fq->filenames.pop_front();
            } else // nothing in the work queue
            {
                return;
            }
        } // lck destroyed here


        // Do work
        ifstream fin(fname.c_str());
        string word;
        int count = 0;
        while (fin >> word) {
            if (word == needle) {
                count++;
            }
        }

        // Store result
        {
            unique_lock<mutex> lck(cq->m);
            cq->counts.push_back(count);
            cq->who.push_back(this_thread::get_id());
        }
    }
}

void functions::reduce(counts* cq){
    while(true) {
        int a,b;

        {
            unique_lock<mutex> lck(cq->m);
            if(cq->counts.size() > 1)
            {
                a = cq->counts.front();
                cq->counts.pop_front();
                b = cq->counts.front();
                cq->counts.pop_front();
            }
            else
            {
                return;
            }
        }

        int sum = a + b;

        {
            unique_lock<mutex> lck(cq->m);
            cq->counts.push_back(sum);
        }
    }
}