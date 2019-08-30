#include <iostream>
#include <string>
#include <fstream>
#include "functions.cpp"

using namespace std;

void readConfig();

//config information
string inputFName;
string inputFType;
int maxFEntries;
string outputFName;

int main() {
    //read configuration file
    readConfig();

    ifstream fin(inputFName);
    ofstream fout(outputFName);

    //file opening check
    if (fin.fail()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    //code branch for each type
    if (inputFType == "int") {
        int a[maxFEntries];

        //code for reading original data from the file into the list
        cout << "The original data:" << endl;
        for (int i = 0; i < maxFEntries; i++) {
            if (!fin.eof()) {
                fin >> a[i];
            } else {
                a[i] = 0;
            }
        }

        //show the original data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //sort the list
        functions<int> lab3;
        lab3.bubbleSort(a, maxFEntries);

        //code for reading sorted data from the array
        cout << "\nSorted data:" << endl;
        for (int j = 0; j < maxFEntries; ++j) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //store the sorted data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                fout << a[j] << endl;
            }
        }
    } else if (inputFType == "float") {
        float a[maxFEntries];

        //code for reading original data from the file
        cout << "The original data:" << endl;
        for (int i = 0; i < maxFEntries; i++) {
            if (!fin.eof()) {
                fin >> a[i];
            } else {
                a[i] = 0;
            }
        }
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        functions<float> lab3;
        lab3.bubbleSort(a, maxFEntries);

        //code for reading sorted data from the array
        cout << "\nSorted data:" << endl;
        for (int j = 0; j < maxFEntries; ++j) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //store the sorted data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                fout << a[j] << endl;
            }
        }
    } else if (inputFType == "double") {
        double a[maxFEntries];
        //code for reading original data from the file
        cout << "The original data:" << endl;
        for (int i = 0; i < maxFEntries; i++) {
            if (!fin.eof()) {
                fin >> a[i];
            } else {
                a[i] = 0;
            }
        }

        //show the original data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //sort the list
        functions<double> lab3;
        lab3.bubbleSort(a, maxFEntries);

        //code for reading sorted data from the array
        cout << "\nSorted data:" << endl;
        for (int j = 0; j < maxFEntries; ++j) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //store the sorted data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                fout << a[j] << endl;
            }
        }
    } else if (inputFType == "long") {
        long a[maxFEntries];

        //code for reading original data from the file
        cout << "The original data:" << endl;
        for (int i = 0; i < maxFEntries; i++) {
            if (!fin.eof()) {
                fin >> a[i];
            } else {
                a[i] = 0;
            }
        }

        //show the original data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //sort the list
        functions<long> lab3;
        lab3.bubbleSort(a, maxFEntries);

        //code for reading sorted data from the array
        cout << "\nSorted data:" << endl;
        for (int j = 0; j < maxFEntries; ++j) {
            if (a[j] != 0) {
                cout << a[j] << " ";
            }
        }

        //store the sorted data
        for (int j = 0; j < maxFEntries; j++) {
            if (a[j] != 0) {
                fout << a[j] << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}

/* read configuration file */
void readConfig(){
    ifstream fin("CONFIG.dat");

    //file opening check
    if (fin.fail()) {
        cout << "Error opening file!" << endl;
        exit(0);
    }

    fin >> inputFName;
    fin >> inputFType;
    fin >> maxFEntries;
    fin >> outputFName;

    fin.close();
}