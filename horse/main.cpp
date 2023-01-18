#pragma warning(disable : 4996)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "msoftcon.h"
#include "constants.h"
#include "Track.h"
#include "Horse.h"

using namespace std;

int main()
{
	float length;
	int total;

	cout << "Enter the length of the distance (from 1 to 12): ";
	cin >> length;
	cout << "\nEnter the number of horses (from 1 to 7): ";
	cin >> total;

	Track theTrack(length, total);

	theTrack.run();

	system("pause");
	return 0;
}