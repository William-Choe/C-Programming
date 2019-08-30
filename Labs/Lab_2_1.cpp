#include "Lab_2_1.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

Lab_2_1::Lab_2_1(){
    ifstream fin;
    ofstream fout;

    int a[100];
    string infile;
    string outfile;

    //generate test file with random integers
    generateInt();

    //code for opening the test file
    do {
        fin.clear();
        cout << ">> Enter name of file to connect to:";
        cin >> infile;
        fin.open(infile);
    } while (!fin);

    //code for reading original data from the file
    cout << "The original data:" << endl;
    for (int i = 0; i < 100; ++i) {
        if (!fin.eof()) {
            fin >> a[i];
        } else {
            a[i] = 0;
        }
    }
    for (int j = 0; j < 100; ++j) {
        if (a[j] != 0) {
            cout << a[j] << " ";
        }
    }

    //sort the array
    bubbleSort(a, 100);

    //code for reading sorted data from the array
    cout << "\nSorted data:" << endl;
    for (int j = 0; j < 100; ++j) {
        if (a[j] != 0) {
            cout << a[j] << " ";
        }
    }

    //code for prompt user to create a file to store the sorted list
    cout << "\n\n>> Enter name of file to store the sorted list:";
    cin >> outfile;
    fout.open(outfile);
    for (int j = 0; j < 100; ++j) {
        if (a[j] != 0) {
            fout << a[j] << endl;
        }
    }

    cout << "File created successfully!" << endl;

    fin.close();
    fout.close();
}

/*bubble sort method*/
void Lab_2_1::bubbleSort(int *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*method to generate a random number of integers in the test file.*/
void Lab_2_1::generateInt(){
    ofstream fout("input.dat");

    srand(int(time(0)));
    for (int i = 0; i < rand() % 100; ++i) {
        fout << rand() % 100 << endl;
    }

    fout.close();
}
