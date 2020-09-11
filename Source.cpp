/*
C++ Simulation Tortoise and Hare
Tuyet Nhi Ngo
CIS 54 C/C++ Programming
04-25-2020
*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int finishLine = 70;

void moveTortoise(int*);
void moveHare(int*);
void printPositions(int, int);

int main()
{
	int T = 1;
	int H = 1;
	int timer = 0;

	srand(time(0));

	cout << "(Simulation: The Tortoise and the Hare)" << endl;
	cout << "Bang!!!!!" << endl;
	cout << "And they're off" << endl;

	//move until one of them finish the race
	while (T != finishLine && H != finishLine)
	{
		moveTortoise(&T);
		moveHare(&H);
		printPositions(T, H);
		timer++; //calculate the timer
	}

	//print result
	if (T > H)
	{
		cout << "Tortoise wins!!! Yay!!!" << endl;
	}
	else if (H > T)
	{
		cout << "Hare wins. Yuch" << endl;
	}
	else  //if they both reach the finish line at the same time
	{
		cout << "It's a tie." << endl;
	}


	cout << "Time Elapsed: " << timer << " seconds" << endl;

	return 0;
}

void moveTortoise(int* tortoisePtr)
{
	int x = 1 + rand() % 10; //generate random value

	if (x <= 1 && x <= 5) //fast pod
	{
		*tortoisePtr += 3; //3 squares to the right
	}
	else if (x >= 6 && x <= 7) //slip
	{
		*tortoisePtr -= 6; //6 square to the left
	}
	else
		*tortoisePtr += 1; //1 square to the right

	if (*tortoisePtr < 1)
	{
		*tortoisePtr = 1;
	}
	else if (*tortoisePtr > finishLine)
	{
		*tortoisePtr = finishLine;
	}
}

void moveHare(int* harePtr)
{
	int y = 1 + rand() % 10; //generate random value

	if (y >= 1 && y <= 2) //sleep
	{
		*harePtr = *harePtr; //no move at all
	}
	else if (y >= 3 && y <= 4) //big hop
	{
		*harePtr += 9; //9 squares to the right
	}
	else if (y == 5) //big slip
	{
		*harePtr -= 12; //12 squares to the left
	}
	else if (y >= 6 && y <= 8) //small hop
	{
		*harePtr += 1; //1 square to the right
	}
	else //small slip
	{
		*harePtr -= 2; //2 square to the left
	}

	if (*harePtr < 1)
	{
		*harePtr = 1;
	}
	else if (*harePtr > finishLine)
	{
		*harePtr = finishLine;
	}
}

void printPositions(int T, int H)
{
	cout << setfill(' ');

	if (H == T)
	{
		cout << setw(H) << "Ouch!!!";
	}
	else if (H < T)
	{
		cout << setw(H) << "H" << setw(T - H) << "T";
	}
	else
	{
		cout << setw(T) << "T" << setw(H - T) << "H";
	}

	cout << endl;
}
