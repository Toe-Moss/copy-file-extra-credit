/*
 *        File: copy_file.cc
 *      Author: Tomas Sanchez
 *        Date: March 05, 2019
 * Description: Demonstrate output streams
 *              * uses new function that copies from input file to output file using the 'getline' function *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
void copy(ifstream& inStream, ofstream& outStream); //doesn't return a value, sets 'inStream' and 'outStream' as reference parameters.

int main(int argc, char const *argv[]) {\
    ifstream inStream;
    ofstream outStream;
    
    string inFileName, outFileName;
 
    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName.c_str());
    //check for failure
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outStream.open(outFileName.c_str());
    //check for failure

    copy(inStream, outStream); //calls 'copy();' function.

    inStream.close();
    outStream.close();
    return 0;
}// main

void copy(ifstream& inStream, ofstream& outStream){

    string ch;                 //initializes variable 'ch' as a string.

    getline(inStream, ch);     //calls getline function using 'inStream' as the stream object and 'ch' as the variable.
    while(!inStream.eof()){  
        outStream << ch;       //same as 'cout' but writes to the 'outSream' file.
        outStream.put('\n');   //includes all white spaces.
        getline(inStream, ch); //updates the input for the while loop.
    }
}

/* Extra credit(Due: Tuesday 3/5/2019 11:59 PM):
 * Modify the copy program (above) by doing the copying in a function that takes an input
 * stream and an output stream as parameters. It should copy all the lines from the input stream to the
 * output stream. For example: copy(inStream, outStream);
 * The function must use the getline function to copy all the data.
 * Create a public repository on GitHub, push your code to the repository and
 * tag me (@nasseef) in the final commit message. Please make sure your program works
 * before you tag me.
 */