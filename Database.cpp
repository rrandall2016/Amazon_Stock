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

void printRecord(const Amazon number[], int record){//RECORD caps?
    cout << endl;
    cout << "Outputting record: " << record+1 << endl;
    cout << left
         << setw(15) << number[record+1].date << " ";
    cout << setw(12) << number[record+1].close << " ";
    cout << setw(12) << number[record+1].volume << " ";
    cout << setw(12) << number[record+1].open << " ";
    cout << setw(12) << number[record+1].high << " ";
    cout << setw(12) << number[record+1].low << " ";
    cout << endl;
 }

int postitiveGains(const Amazon number[], int size){
    int totalPositive = 0;
    cout << endl;
    cout << "Dates with positive returns: " << endl;
    for (int i = 0; i < size; i++)
    {
        if(number[i].close > number[i].open){
        cout << "Dates: " << number[i].date << " " << "Amount positive: " << number[i].close - number[i].open << endl;
        totalPositive += 1;
        }
    }
  cout << endl;
  cout << "Total days with positive returns: " << totalPositive << endl;
  return totalPositive;
}

int negativeGains(const Amazon number[], int size){
    int totalNegative = 0;
    cout << endl;
    cout << "Dates with negative returns: " << endl;
    for (int i = 0; i < size; i++)
    {
        if(number[i].close < number[i].open){
        cout << "Dates: " << number[i].date << " " << "Amount Negative: " << (number[i].close - number[i].open) * -1 << endl;
        totalNegative+= 1;
        }
    }
    cout << endl;
    cout << "Total days with negative returns: " << totalNegative << endl;
    return totalNegative;

}

double maxClosing(const Amazon number[], int size){
    double highest = 0;
    int position;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if(number[i].close > highest){
            highest = number[i].close;
            position = i;
        }
    }

  cout << "Highest closing amount: " << highest << endl;
  cout << "Outputting highest amount record: " << position << endl;
  cout << left
       << setw(15) << number[position].date << " ";
  cout << setw(12) << number[position].close << " ";
  cout << setw(12) << number[position].volume << " ";
  cout << setw(12) << number[position].open << " ";
  cout << setw(12) << number[position].high << " ";
  cout << setw(12) << number[position].low << " ";
  cout << endl;

  return highest;
}

double minClosing(const Amazon number[], int size){
    double lowest = number[0].close;
    int position;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (number[i].close < lowest){
            lowest = number[i].close;
            position = i;
        }
    }

  cout << "Lowest closing amount: " << lowest << endl;
  cout << "Outputting lowest amount record: " << position << endl;
  cout << left
       << setw(15) << number[position].date << " ";
  cout << setw(12) << number[position].close << " ";
  cout << setw(12) << number[position].volume << " ";
  cout << setw(12) << number[position].open << " ";
  cout << setw(12) << number[position].high << " ";
  cout << setw(12) << number[position].low << " ";
  cout << endl;

  return lowest;

}
double average(const Amazon number[], int size){
    double sum = 0;
    double average;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
       sum += number[i].close;
    }
    average = sum / size;

  cout << "The average closing amount for the input size is : " << average << endl;
  return average;


}

