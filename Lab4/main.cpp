#include "functions.h"
#include <iostream>
#include <string>
#include <thread>
#include <fstream>

using namespace std;

thread mappers[4];
thread reducers[4];

int main(int argc, char *argv[]) {
    // default search word
    string needle = "the";

    // assume the user is passing the target string in the execution call
    if (argc == 2){
        needle = argv[1];
    }

    files fq;
    counts cq;

    // setup some sample files for the threads to read...
    // (to give it "enough" data, files are processed multiple times :)
    ifstream fin("files.dat");
    for(int i = 0; i < 10; i++)
    {
        string fileName;
        if (!fin.eof()) {
            fin >> fileName;
        }
        fq.filenames.emplace_back(fileName);
    }
    fin.close();

    for(auto & mapper : mappers){
        mapper = thread(functions::map ,&fq, &cq, needle);
    }

    // make sure all threads have finished work and join main before continuing
    for(auto& m : mappers){
        m.join();
    }

    // all counting has completed, proceed to analyze individual counts
    auto whoit = cq.who.begin();
    for(auto& i : cq.counts){
        cout << *whoit << " " << i << endl;
        whoit++;
    }


    for(auto & reducer : reducers){
        reducer = thread(functions::reduce,&cq);
    }

    for(auto& r : reducers){
        r.join();
    }

    cout << "Final count: " << endl;
    for(auto& i : cq.counts){
        cout << i << endl;
    }
}