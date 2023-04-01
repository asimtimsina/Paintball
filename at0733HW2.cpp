/* Author: Asim Timsina (asimtimsina@my.unt.edu)
 Date: 02/22/2020
 Instructor: Helsing Joseph
 Description:  Project 2 Assignment
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;


enum option { OPPONENT = 'O', PARTNER = 'P' };  // declare enum option for opponent and partner


int main () 

{





	const int SIZE = 10;

	int xopponent, yopponent;	// to save the opponent coordinate
	int xpartner, ypartner;	// to save the partner coordinate
	int userx = 0, usery = 0;	// to get the coordinate from the user
	bool test = false, partnercheck = false;	// bool to check whether user found the opponent or partner or not
	char chance;

	int remchance = 3;		// chance to user to find partner or opponent



	srand (time (0));
	// randomly generating the coordinates of opponent and partner and checking if they are not the same    
	do
	{

		xopponent = rand () % SIZE;

		yopponent = rand () % SIZE;

		xpartner = rand () % SIZE;

		ypartner = rand () % SIZE;

	}
	while ((xopponent == xpartner) && (yopponent == ypartner));

/*
	//  This is for checking the program while being developed.
	cout << "opponent " << xopponent << " " << yopponent << endl;

	cout << "Partner  " << xpartner << " " << ypartner << endl;

	cout << "User  " << userx << " " << usery << " " << chance << endl;

*/

	while (remchance > 0)
	{

		do
		{

			test = false;

			cout << "Enter your guess (x and y values ) (0-9) :";

			cin >> userx >> usery;


			if (!((userx >= 0) && (userx < 10) && (usery >= 0) && (usery < 10)))	// checking if user coordinates is feasible or not
			{

				cout << "Invalid guess" << endl;

				test = true;

			}



		}
		while (test);


		// cout << test ;

		do
		{

			test = false;

			cout <<
				"Do you want to attack your Opponent(O) or find your Partner(P) :";

			cin >> chance;


			if (!((toupper (chance) == 'P') || (toupper (chance) == 'O')))	//checking if user entered O, o , P , p or not 
			{

				cout << " Invalid find mode. Please try again" << endl;

				test = true;

			}


		}
		while (test);



		chance = toupper (chance);


		switch (chance)	// switch case for different cases
		{

			case 'O':		// if user enters to find opponent
				if ((userx == xopponent) && (usery == yopponent))	// if user inputs equals the opponent coordinates
				{

					cout << "Congratulations.You shot your opponent. You own." <<
						endl;

					return 0;

				}

				else if ((userx == xpartner) && (usery == ypartner))	// if user inputs equals the partner coordinate
				{

					cout << "Oops. You shot your Partner. Game over." << endl;

					return 0;

				}

				else

				{

					cout << "You missed your opponent." << endl;	// if user inputs is different than coordinate of opponent or Partner
					cout << "You have " << --remchance << " tries remaining." <<
						endl;

					if (remchance == 0)

					{

						cout << "You've finished all tries. Game over." << endl;

						return 0;

					}


				}
					cout << endl ;
				break;

			case 'P':


				if (partnercheck)	// if user choose to find partner
				{

					cout <<
						"You've already found your partner, don't cheat. You lose a try."
						<< endl;

					cout << "You have " << --remchance << " tries remaining." <<
						endl;
					cout << endl ;
					break;

				}

				if ((userx == xpartner) && (usery == ypartner))

				{

					cout << "You found your partner." << endl;	// if user found partner while choosing partner remainging tries doubles
					remchance = remchance * 2;

					partnercheck = true;

					cout << "You have " << remchance << " tries remaining." <<
						endl;

				}

				else if ((userx == xopponent) && (usery == yopponent))	// // if user inputs equals the opponent coordinate
				{

					cout << "Oops, you alerted your opponent. You lose. Game over"
						<< endl;

					return 0;

				}

				else

				{

					cout << "You missed your Partner." << endl;	// if user inputs is different than coordinate of opponent or Partner
					cout << "You have " << --remchance << " tries remaining." <<
						endl;

					if (remchance == 0)

					{

						cout << "You've finished all tries. Game over." << endl;

						return 0;

					}




				}
						cout << endl;
				break;


			default:

				cout << " Invalid selection." << endl;

				cout << " please try again." << endl;

				break;

		}




	}







	cout << "opponent " << xopponent << " " << yopponent << endl;

	cout << "Partner  " << xpartner << " " << ypartner << endl;

	cout << "User  " << userx << " " << usery << " " << chance << endl;





	return 0;


}


