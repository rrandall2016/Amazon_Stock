/**
* @brief Assignment 9
* @name Randy Randall
*/
#include "Database.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <array>
using namespace std;


int main()
{
    //Title: Amazon Stock Anyalsis Since The Pandemic
    cout << "Amazon Stock Anyalsis Since The Pandemic" << endl;
    cout << endl;

    //How many records to input to system- record seeking to output must be <= to amount
    const int AMOUNT = 190;
    //How many records to input into the data anylsis functions
    //This will also change how many positive and negative days print out
    const int OUTPUT = 20;

    //How many records will output
    //This is the number I recommend changing to your specifics
    const int DATA = 20;

    //Choose which two records to print all information
    //Record index starts at 0
    const int RECORD1 = 2;
    const int RECORD2 = 5;

    //Declare array of size AMOUNT
    Amazon stocks[AMOUNT];
    
    //In stream Infile object for inputing files
    ifstream inFile;
    inFile.open("AmazonStock.csv");

    //If inFile fails to open file, exit.
    if (!inFile){
        cerr << "File can't be opened! " << endl;
        system("PAUSE");
        exit(1);
    }


    //Header date[0], close amount[1], volume of stocks[2], open amount[3], high of day[4], and low of day[5]
    string header[6];
    string trash;
    for(int i = 0; i < 5; i++){
        getline(inFile, header[i], ',');
    }
        getline(inFile, header[5], ',');
        getline(inFile, trash, '\n');

    //Acutal printing of header
    cout << right<< setw(0) << header[0] << setw(22) << header[1] << setw(9) << header[2] << setw(11) << header[3] << setw(13) << header[4] << setw(12) << header[5] << endl;
    cout << endl;


    //Input from file for data
    for (int i=0; i < AMOUNT; i++){
        string date, close, volume, open, high, low;
        getline(inFile, date, ',');
        stocks[i].date = date;
        getline(inFile, close, ',');
        double closeConvert = stod(close);
        stocks[i].close = closeConvert;
        getline(inFile, volume, ',');
        long volumeConvert = stol(volume);
        stocks[i].volume = volumeConvert;
        getline(inFile, open, ',');
        double openConvert = stod(open);
        stocks[i].open = openConvert;
        getline(inFile, high, ',');
        double highConvert = stod(high);
        stocks[i].high = highConvert;
        getline(inFile, low, '\n');
        double lowConvert = stod(low);
        stocks[i].low = lowConvert;

        if (inFile.fail())
            break;
    }

    for (int i=0;i< DATA;i++) {
        cout << left
             << setw(15) << stocks[i].date << " ";
        cout << setw(12) << stocks[i].close << " ";
        cout << setw(12) << stocks[i].volume << " ";
        cout << setw(12) << stocks[i].open << " ";
        cout << setw(12) << stocks[i].high << " ";
        cout << setw(12) << stocks[i].low << " ";
        cout << endl;
    }

//    //Testing specific construct/record calls
//    cout << "Testing" << endl;
//    cout << stocks[20].volume << endl;// Works!

    //Part 3: Output a particular record using functions
    //Constant located above as RECORD1 AND RECORD2
    printRecord(stocks, RECORD1-1);
    printRecord(stocks, RECORD2-1);

    //Part 4 : Output matching records
    //Output days positive, and the total positive days within your defined amount of records
    //Same for negatives as above
    //Thirdly this will output the TOTAL number of positive days
    //User can change OUTPUT to how many records back they wish to go.
    //Advised to make them the same number in the positive AND negative functions for proper comparison.

    int x = postitiveGains(stocks, OUTPUT);
    int y = negativeGains(stocks,OUTPUT);
    int difference = x - y;
    cout << "\nHow many days positive vs negative: " << difference << endl;


    //Part 5 : Find Max/Min/Average
    maxClosing(stocks, OUTPUT);
    minClosing(stocks, OUTPUT);
    average(stocks, OUTPUT);

    //Part 6: Outputs the total stock gain since start of pandemic
    cout << endl;
    cout << "Amazon gain on stock compared to annouced date of pandemic in the US (3/11/2020): ";
    double gains = stocks[0].close - stocks[185].close;
    cout << gains << endl;

    inFile.close();
    
    return 0;

}
