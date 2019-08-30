#include "Lab_2_2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;

Lab_2_2::Lab_2_2(){
    ifstream fin;
    ofstream fout;

    string infile;
    string outfile;

    //generate test file with random length of strings and get the number of strings
    int n = generateString();
    string a[n];


    //code for opening the test file
    do {
        fin.clear();
        cout << ">> Enter name of file to connect to:";
        cin >> infile;
        fin.open(infile);
    } while (!fin);

    //code for reading original data from the file
    cout << "The original data:" << endl;
    for (int i = 0; i < n; i++) {
        if (!fin.eof()) {
            fin >> a[i];
        }

    }
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }

    //sort the array
    bubbleSort(a, n);

    //code for reading sorted data from the array
    cout << "\nSorted data:" << endl;
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }

    //code for prompt user to create a file to store the sorted list
    cout << "\n\n>> Enter name of file to store the sorted list:";
    cin >> outfile;
    fout.open(outfile);
    for (int j = 0; j < n; j++) {
        fout << a[j] << endl;
    }

    cout << "File created successfully!" << endl;

    fin.close();
    fout.close();
}

/*bubble sort method*/
void Lab_2_2::bubbleSort(string *arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].data(), arr[j + 1].data())) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*method to generate a random number of integers in the test file.*/
int Lab_2_2::generateString(){
    ofstream fout("input.dat");

    srand(int(time(0)));

    //number of randomly generated strings
    int n = rand() % 15 + 1;

    for (int i = 0; i < n; ++i) {
        //randomly generated string length
        int k = rand() % 10 + 1;
        for (int j = 0; j <= k; ++j) {
            //X represents the ASCII code of the character, and S represents the case of the character
            int x, s;
            //1 is uppercase, 0 is lowercase
            s = rand() % 2;

            if (s == 1) {
                x = rand() % ('Z' - 'A' + 1) + 'A';
            } else {
                x = rand() % ('z' - 'a' + 1) + 'a';
            }

            fout << (char)x;
        }
        fout << endl;
    }

    fout.close();
    return n;
}