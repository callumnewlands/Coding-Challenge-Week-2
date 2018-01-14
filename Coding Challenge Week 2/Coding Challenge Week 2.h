#pragma once

const int FIFTY_IN_PENNIES = 5000;
const int TWENTY_IN_PENNIES = 2000;
const int TEN_IN_PENNIES = 1000;
const int FIVE_IN_PENNIES = 500;
const int TWO_IN_PENNIES = 200;
const int ONE_POUND_IN_PENNIES = 100;
const char POUND_SIGN = char(156);
const int NUMBER_OF_COINS = 12;

bool isCurrencyFormat(float);
float roundToDP(float, int);
int* getCoinList();
float getCost();
float getPaid();
void getCoins(float);
void outputForPennies(int&, int);
void outputForPounds(int&, int);