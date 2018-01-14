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
const int NUMBER_OF_COINS = 12;

bool isCurrencyFormat(float);
float roundToDP(float, int);
int* getCoinList();
float GetCost();
float GetPaid();
void GetCoins(float);
void outputForPennies(int&, int);
void outputForPounds(int&, int);

int main()
{
	float cost = GetCost();

	float change;
	do	
	{
		float paid = GetPaid();
		change = paid - cost;
	} while (change < 0); //ensures payment is >= cost

	GetCoins(change);

    return 0;
}

float GetCost()
{
	float cost;
	do
	{
		std::cout << "Please enter the cost: " << POUND_SIGN;
		std::cin >> cost;
	} while (!isCurrencyFormat(cost));
	return cost;
}

float GetPaid()
{
	float paid;
	do
	{
		std::cout << "Please enter the amount paid: " << POUND_SIGN;
		std::cin >> paid;
	} while (!isCurrencyFormat(paid));
	return paid;
}

void GetCoins(float change)
{	

	std::cout << std::endl << "Change: " << POUND_SIGN << change << std::endl;

	int* coins = getCoinList();

	int remainingPennies = change * 100;

	for (int i = 0; i < NUMBER_OF_COINS; i++)
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

	delete[NUMBER_OF_COINS] coins;
}

int* getCoinList()
{
	int* coins = new int[NUMBER_OF_COINS]{FIFTY_IN_PENNIES, TWENTY_IN_PENNIES, TEN_IN_PENNIES, FIVE_IN_PENNIES, TWO_IN_PENNIES, ONE_POUND_IN_PENNIES, 50, 20, 10, 5, 2, 1 };
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