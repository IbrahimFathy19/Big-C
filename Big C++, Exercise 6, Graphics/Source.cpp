/*****************************************************************************************************
***********************************Big C++, Exercise**************************************************
******************************Ibrahim Fathy Abd Elmageed**********************************************
*************The problems are divided into functions, each function indicates the name****************
*************of the problem, for example function p1 stands for problem 1****************************/


#include "ccc_win.h"
#include "polygon.h"
#include "Cross.h"
#include <vector>

/**
Checks who wins by checking the data(x and y) of shape of one data type
say Circles
@return 1 if a player wins
*/
int check_winner(const std::vector<double> & x, const std::vector<double> & y);
int Tic_Tac_Toe();


int ccc_win_main()
{
#if 0 // Test Polygon Class
	polygon s;
	s.add_point(Point(0, 0));
	s.add_point(Point(0, 2));
	s.add_point(Point(1, 2));
	s.add_point(Point(1, 0));
	s.plot();
	double x = s.perimeter();
	Message d(Point(5, 5), x);

	s.scale(2);
	s.plot();
	s.move(4, 0);
	s.plot();
	double a = s.area();
	Message z(Point(-5, -5), a);
	cwin << d << z;
#endif

	std::string try_again;
	std::string clear = "clr";
	while (true)
	{
		Tic_Tac_Toe();
		clear = cwin.get_string("Type clr to try again");

		while (clear != "clr")
			clear = cwin.get_string("Type clr to clear the screen!");
		cwin.clear();

	}

	return 0;
}
int Tic_Tac_Toe()
{
	// Tic-Tac-Toe
	// Display the grid 
	Line horizontal(Point(-3, 1), Point(3, 1)), vertical(Point(-1, 3), Point(-1, -3));
	cwin << horizontal << vertical;
	horizontal.move(0, -2); vertical.move(2, 0);
	cwin << horizontal << vertical;
	cwin << horizontal << vertical;

	const int Number_plays = 9; // Max number of plays ,, we have 9 boxes
	int i = 0, index = 0; // index is a variable to index the vectors o and x
	std::vector<Circle> o; // Vector to hold all circles or Os
	std::vector<Cross> x; // Vector to hold all Corsses or Xs

	std::vector<double> x_axis_o; // Vector to hold x values of the center of the Circles
	std::vector<double> y_axis_o; // Vector to hold y values of the center of the Circles

	std::vector<double> x_axis_x; // Vector to hold x values of the intersection point
								  // of the Crosses
	std::vector<double> y_axis_x; // Vector to hold y values of the intersection point
								  // of the Crosses

	Point play; // The point used to display the circle (Center Point) or the Cross(
				// intersction Point)
	Message announce_winner;
	int winner;
	while (i < Number_plays)
	{
		play = cwin.get_mouse("First Player turn O!");
		o.push_back(Circle(play, .5)); // Fill the circles vector
		cwin << o[index];

		x_axis_o.push_back(play.get_x()); // Fill the x value of the center of the 
										  // given circle
		y_axis_o.push_back(play.get_y());// Fill the y value of the center of the 
										 // given circle

		winner = check_winner(x_axis_o, y_axis_o); // check the winner using the x and y data
		if (winner) // winner == 1 if the player wins
		{
			announce_winner = Message(Point(-4, 7), "Player 1 wins O!");
			cwin << announce_winner;
			return 0;
		}
		i++; // increase the number of plays
		if (i < Number_plays - 1) // To check if i equals 7 because i will increase 
								  // here again and it will be 8 , so it can enter the loop and become 9, therefor 
								  // it shouldn't pass this if condition, 9 is the max number of plays
		{
			play = cwin.get_mouse("Second Player turn X!");
			x.push_back(Cross(play, 1, 1));
			x[index].plot();

			x_axis_x.push_back(play.get_x());
			y_axis_x.push_back(play.get_y());

			winner = check_winner(x_axis_x, y_axis_x);
			if (winner)
			{
				announce_winner = Message(Point(-4, 7), "Player 2 wins X!");
				cwin << announce_winner;
				return 0;
			}
			i++;
		}
		index++;
	}
	announce_winner = Message(Point(-4, 7), "No one wins!"); // No one wins
	cwin << announce_winner;
	return 1;
}
int check_winner(const std::vector<double>& x, const std::vector<double>& y)
{
	int x_size = x.size(), y_size = y.size();
	if (x_size < 3 || y_size < 3)
		return 0; // No one Wins

				  // 1 is the borders of +x and +y , see the board in Tic_Tac_Toe function 
				  /** we count how many shape (Circle or Cross) is above 1 (y > 1), if 3, then this shape
				  wins. Likewise if y is between 1 and -1 and the number of shapes is 3. Same
				  goes to x as well*/
	int y_larger_than_1 = 0, y_smaller_than_1 = 0, y_in_between = 0;
	int x_larger_than_1 = 0, x_smaller_than_1 = 0, x_in_between = 0;
	int first_diagonal = 0, second_diagonal = 0;
	for (int i = 0; i < y_size; i++)
	{
		if (y[i] > 1)
			y_larger_than_1++;
		else if (y[i] < -1)
			y_smaller_than_1++;
		else if (y[i] > -1 && y[i] < 1)
			y_in_between++;

		if (x[i] > 1)
			x_larger_than_1++;
		else if (x[i] < -1)
			x_smaller_than_1++;
		else if (x[i] > -1 && x[i] < 1)
			x_in_between++;

		if (x[i] > -1 && x[i] < 1 && y[i] > -1 && y[i] < 1)
		{
			first_diagonal++;
			second_diagonal++;
		}
		else if (x[i] > 1 && y[i] > 1
			|| x[i] < -1 && y[i] < -1)
			first_diagonal++;

		else if (x[i] < -1 && y[i] > 1
			|| x[i] > 1 && y[i] < -1)
			second_diagonal++;

		//
		if (y_larger_than_1 == 3 || y_smaller_than_1 == 3 || y_in_between == 3)
			return 1; //Player wins
		else if (x_larger_than_1 == 3 || x_smaller_than_1 == 3 || x_in_between == 3)
			return 1; //Player wins
		else if (first_diagonal == 3 || second_diagonal == 3)
			return 1; //Player wins
	}
	return 0; // No one wins.
}
