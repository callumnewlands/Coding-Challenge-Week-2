// Coding Challenge Week 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

const int FIFTY_IN_PENNIES = 5000;
const int TWENTY_IN_PENNIES = 2000;
const int TEN_IN_PENNIES = 1000;
const int FIVE_IN_PENNIES = 500;
const int TWO_IN_PENNIES = 200;
const int ONE_POUND_IN_PENNIES = 100;
const char POUND_SIGN = char(156);

bool isCurrencyFormat(float);
float roundToDP(float, int);
int* getCoinList();
void outputForPennies(int&, int);
void outputForPounds(int&, int);

int main()
{
	float cost;
	do
	{
		std::cout << "Please enter the cost: " << POUND_SIGN;
		std::cin >> cost;
	} while (!isCurrencyFormat(cost));

	float change;
	do
	{
		float paid; 
		do
		{
			std::cout << "Please enter the amount paid: " << POUND_SIGN;
			std::cin >> paid;
		} while (!isCurrencyFormat(paid));
		change = paid - cost;
	} while (change < 0); //ensures payment is >= cost
	
	std::cout << std::endl << "Change: " << POUND_SIGN << change << std::endl;

	int* coins = getCoinList();
	int numberOfCoins = 12;

	//int changeInPennies = change * 100;

	/*for (int* ptr = coins; ptr < coins + numberOfCoins; ptr++)
	{
		int coin = *ptr;
	}*/

	int remainingPennies = change * 100;

	for (int i = 0; i < numberOfCoins; i++)
	{
		int coin = coins[i];
		if (coin < ONE_POUND_IN_PENNIES)
		{
			outputForPennies(remainingPennies, coin);
		}
		else
		{
			outputForPounds(remainingPennies, coin);
		}
	}
/*
	int fifties = changeInPennies / FIFTY_IN_PENNIES;
	if (fifties > 0) std::cout << POUND_SIGN << "50: " << fifties << std::endl;
	int remainder = changeInPennies % FIFTY_IN_PENNIES;

	int twenties = remainder / TWENTY_IN_PENNIES;
	if (twenties > 0) std::cout << POUND_SIGN << "20: " << twenties << std::endl;
	remainder = remainder % TWENTY_IN_PENNIES;
	
	int tens = remainder / TEN_IN_PENNIES;
	if (tens > 0) std::cout << POUND_SIGN << "10: " << tens << std::endl;
	remainder = remainder % TEN_IN_PENNIES;

	int fives = remainder / FIVE_IN_PENNIES;
	if (fives > 0) std::cout << POUND_SIGN << "5: " << fives << std::endl;
	remainder = remainder % FIVE_IN_PENNIES;

	int twos = remainder / TWO_IN_PENNIES;
	if (twos > 0) std::cout << POUND_SIGN << "2: " << twos << std::endl;
	remainder = remainder % TWO_IN_PENNIES;

	int ones = remainder / ONE_POUND_IN_PENNIES;
	if (ones > 0) std::cout << POUND_SIGN << "1: " << ones << std::endl;
	remainder = remainder % ONE_POUND_IN_PENNIES;
	
	int fiftyPences = remainder / 50;
	if (fiftyPences > 0) std::cout << "50p: " << fiftyPences << std::endl;
	remainder = remainder % 50;

	int twentyPences = remainder / 20;
	if (twentyPences > 0) std::cout << "20p: " << twentyPences << std::endl;
	remainder = remainder % 20;

	int tenPences = remainder / 10;
	if (tenPences > 0) std::cout << "10p: " << tenPences << std::endl;
	remainder = remainder % 10;

	int fivePences = remainder / 5;
	if (fivePences > 0) std::cout << "5p: " << fivePences << std::endl;
	remainder = remainder % 5;
	
	int twoPences = remainder / 2;
	if (twoPences > 0) std::cout << "2p: " << twoPences << std::endl;
	remainder = remainder % 2;

	if (remainder > 0) std::cout << "1p: " << remainder << std::endl;*/

    return 0;
}

int* getCoinList()
{
	static int coins[] = { FIFTY_IN_PENNIES, TWENTY_IN_PENNIES, TEN_IN_PENNIES, FIVE_IN_PENNIES, TWO_IN_PENNIES, ONE_POUND_IN_PENNIES, 50, 20, 10, 5, 2, 1 };
	return coins;
}

bool isCurrencyFormat(float data)
{
	return roundToDP(data, 2) == data;
}

float roundToDP(float data, int precision)
{
	return std::floor(data * (float)std::pow(10, precision)) / (float)std::pow(10, precision);
}
// recursive poundChange and PennyCHange fubnctionsd

void outputForPennies(int &remaningPennies, int coin)
{
	int number = remaningPennies / coin;
	if (number > 0)
	{
		std::cout << coin << "p: " << number << std::endl;
		remaningPennies = remaningPennies % coin;
	}
}

void outputForPounds(int &remaningPennies, int coin)
{
	int number = remaningPennies / coin;
	if (number > 0)
	{
		std::cout << POUND_SIGN << coin / 100 << ": " << number << std::endl;
		remaningPennies = remaningPennies % coin;
	}
}