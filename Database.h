/**
* @brief Assignment 9
* @name Randy Randall
*/

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <array>
using namespace std;


struct Amazon {
    string date;
    double close;
    long volume;
    double open;
    double high;
    double low;
};


/**
 * @brief  Prints out entire records
 * @param  const array and const amount of records
 * @return void
 *
 */

void printRecord(const Amazon number[], const int RECORD);

/**
 * @brief  Calculates what days that were a positive return and how many days total within a specific size of records
 * @param  const array, size of records
 * @return int positive days
 *
 */
int postitiveGains(const Amazon number[], int size);

/**
 * @brief  Calculates what days that were a negative return and how many days total within a specific size of records
 * @param  const array, size of records
 * @return int negative days
 *
 */
int negativeGains(const Amazon number[], int size);

/**
 * @brief  Searches for the highest closing amount and outputs that amount and the record associated
 * @param  const array, size of records
 * @return double max amount
 *
 */
double maxClosing(const Amazon number[], int size);

/**
 * @brief  Searches for the lowest closing amount and outputs that amount and the record associated
 * @param  const array, size of records
 * @return double min amount
 *
 */
double minClosing(const Amazon number[], int size);

/**
 * @brief  Calculates the average stock price and outputs that amount considering closing price
 * @param  const array, size of records
 * @return double average
 *
 */
double average(const Amazon number[], int size);

/**
 * @brief  Calculates amount of stock gain compared to first day of pandemic
 * @param  const array, size of records
 * @return double stock gain price
 *
 */
double gains(const Amazon number[], int size);


#endif // DATABASE_H
