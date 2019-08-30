#include "Lab_1.h"
#include <iostream>

using namespace std;

Lab_1::Lab_1() {
    /*Declarations*/
    float cels;
    float fahr;

    /*Greeting*/
    cout << "\n\t\tWelcome to Temperature Conversion Program\n" << endl;

    /*Conversion from Fahrenheit to Celsius*/
    cout << ">> Please enter a temperature in Fahrenheit:";
    //Checks if the input is a number
    while (!(cin >> fahr)) {
        cin.clear();
        cin.sync();
        cout << ">> Please enter a temperature(number) in Fahrenheit:";
    }

    //Computations and Output
    cels = convertFtoC(fahr);
    cout << "Your temperature input of " << fahr << " degrees Fahrenheit is " << cels
         << " degrees celsius." << endl;

    /*Conversion from Celsius to Fahrenheit*/
    cout << "\n>> Please enter a temperature in Celsius:";
    //Checks if the input is a number
    while (!(cin >> cels)) {
        cin.clear();
        cin.sync();
        cout << ">> Please enter a temperature(number) in Celsius:";
    }

    //Computations and Output
    fahr = convertCtoF(cels);
    cout << "Your temperature input of " << cels << " degrees Celsius is " << fahr
         << " degrees fahrenheit." << endl;
}

float  Lab_1::convertCtoF(float degC){
    return degC * 9 / 5 + 32;
}

float Lab_1::convertFtoC(float degF){
    return (degF - 32) * 5 / 9;
}