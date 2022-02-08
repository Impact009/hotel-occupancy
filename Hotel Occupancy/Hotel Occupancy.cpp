// Hotel Occupancy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	// Declare variables to store values for the numbers of floors, occupied rooms, unoccupied rooms, and the percentage of rooms that are occupied.
	char reply = 'n';
	int highestFloor, roomsOnFloor, occupiedRooms = 10, unoccupiedRooms = 30, occupiedTotal = 0, unoccupiedTotal = 0, roomTotal = 40;
	double occupancyPercentage = 25;

	// Program information and example.
	cout << "This program calculates the occupancy rate for the hotel. It will ask how many\n"
		 << "floors the hotel has, the number of rooms on each floor, and how many of them\n"
		 << "are occupied.\n\n"
		 
		 << "For example, if a hotel has " << occupiedRooms << " occupied rooms and " << unoccupiedRooms << " unoccupied rooms, then it\n"
		 << "has " << roomTotal << " rooms, and its occupancy rate is " << occupancyPercentage << "%.\n\n" 

	// Ask the user if he or she wants to enter information.
		 << "This program requires the hotel's highest floor number and the number of\n"
		 << "occupied and unoccupied rooms for each floor. Since it is traditional that most\n"
		 << "hotels do not have a thirteenth floor, this program will exclude it.\n\n"

		 << "For instance, if the hotel has 15 floors, then this program will calculate the\n"
		 << "occupancy rate for 14 floors.\n\n"

		 << "Would you like to enter this information? (y/n) ";
	cin >> reply;

	if (reply == 'y' || reply == 'Y')
	{
		// Clear the screen for calculation.
		system("cls");

		// Input information
		cout << "Enter the hotel's highest floor number:            ";
		cin  >> highestFloor;

		// Validate the input.
		while (highestFloor < 1)
		{
			// Explain the error.
			cout << "Error: the hotel must have at least 1 floor.\n\n"

			// Get the input again.
				 << "Enter the hotel's highest floor number:            ";
			cin  >> highestFloor;
		}

		for (int floor = 1; floor <= highestFloor; floor++)
		{
			if (floor == 13)
				continue; // Immediately start the next iteration
			cout << endl
				 << "Enter the number of rooms on floor " << left << setw(2) << floor << ":             ";
			cin  >> roomsOnFloor;

			// Validate the input.
			while (roomsOnFloor < 10)
			{
				// Explain the error.
				cout << "Error: the hotel must have at least 10 rooms per floor.\n\n"

				// Get the input again.
					 << "Enter the number of rooms on floor " << setw(2) << floor << ":             ";
				cin  >> roomsOnFloor;
			}

			cout << "Enter the number of occupied rooms on floor " << setw(2) << floor << ":    ";
			cin  >> occupiedRooms;
			cout << "Enter the number of unoccupied rooms on floor " << setw(2) << floor << ":  ";
			cin  >> unoccupiedRooms;

			// Validate the input.
			while (occupiedRooms + unoccupiedRooms != roomsOnFloor)
			{
				// Explain the error..
				cout << "Error: the number of occupied and unoccupied rooms don't equal the number of\n"
					 << "rooms on this floor.\n\n"
					
				// Get the input again.
					 << "Enter the number of rooms on floor " << left << setw(2) << floor << ":             ";
				cin  >> roomsOnFloor;
				cout << "Enter the number of occupied rooms on floor " << setw(2) << floor << ":    ";
				cin  >> occupiedRooms;
				cout << "Enter the number of unoccupied rooms on floor " << setw(2) << floor << ":  ";
				cin  >> unoccupiedRooms;
			}

			occupiedTotal += occupiedRooms;
			unoccupiedTotal += unoccupiedRooms;
		}

		// Perform calculations.
		roomTotal = occupiedTotal + unoccupiedTotal;
		occupancyPercentage = static_cast<double>(occupiedTotal) / roomTotal * 100;

		// Outputs data.
		cout << "\nTotal number of rooms: " << roomTotal
			 << "\nOccupied rooms:        " << occupiedTotal
			 << "\nUnoccupied rooms:      " << unoccupiedTotal
			 << "\nOccupancy rate:        " << occupancyPercentage << "%\n";
	}

	cout << "\nHave a great day!\n\n";
	return 0;
}