#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iterator>
#include <random>

using number_type = unsigned short int; 		// <! data type for a keno hit .
using cash_type = float;						// <! Defines the wage type in this application .
using set_of_numbers_type = std::vector<int>;	// <! Defines the vector type in this application.

class KenoBet {

	private:
			set_of_numbers_type m_spots; // <! The player ’s bet.
			cash_type m_wage;			 // <! The player ’s wage.

			set_of_numbers_type round_hits [20];

			std::vector <std::vector< float > > payout_table = 
			{ 																								//Spots bet
			{ 0,   3 }, 																					//1 
			{ 0,   1, 	9 }, 																				//2
			{ 0,   1, 	2,  16 },																			//3
			{ 0, 0.5, 	2,   6,  12 },																		//4
			{ 0, 0.5, 	1,   3,  15, 50 },																	//5
			{ 0, 0.5,   1,   2,   3, 30, 75 },																//6
			{ 0, 0.5, 0.5,   1,   6, 12, 36, 100 },															//7
			{ 0, 0.5, 0.5,   1,   3,  6, 19,  90, 720 },													//8
			{ 0, 0.5, 0.5,   1,   2,  4,  8,  20,  80, 1200 },												//9
			{ 0,   0, 0.5,   1,   2,  3,  5,  10,  30,  600, 1800 },										//10
			{ 0,   0, 0.5,   1,   1,  2,  6,  15,  25,  180, 1000, 3000 },									//11
			{ 0,   0,   0, 0.5,   1,  2,  4,  24,  72,  250,  500, 2000, 4000 },							//12
			{ 0,   0,   0, 0.5, 0.5,  3,  4,   5,  20,   80,  240,  500, 3000, 6000 },						//13
			{ 0,   0,   0, 0.5, 0.5,  2,  3,   5,  12,   50,  150,  500, 1000, 2000, 7500 },				//14
			{ 0,   0,   0, 0.5, 0.5,  1,  2,   5,  15,   50,  150,  300,  600, 1200, 2500, 10000 }			//15

		/*  { 0,   1,   2,   3,   4,  5,  6,   7,   8,    9,   10,   11,   12,   13,   14,    15 } */
											/* Spot hits*/	
			};

	
	public:
		
		// ! Creates an empty Keno bet .
		KenoBet();

		/* ! Adds a number to the spots only if the number is not already there .
			@param spot_ The number we wish to include in the bet .
			@return T if number chosen is successfully inserted ; F otherwise . */
		bool add_number ( number_type spot_ );

		/* ! Sets the amount of money the player is betting .
			@param wage_ The wage .
			@return True if we have a wage above zero ; false otherwise . */
		bool set_wage ( cash_type wage_ );


		// ! Resets a bet to an empty state .
		void reset ( void );
				
		/* ! Retrieves the player ’s wage on this bet .
			@return The wage value . */
		cash_type get_wage ( void ) const;
				
		/* !Returns to the current number of spots in the player’s bet .
			@return Number of spots present in the bet . */
		size_t size ( void ) const;

		/* ! Determine how many spots match the hits passed as argument .
			@param hits_ List of hits randomly chosen by the computer .
			@return An vector with the list of hits . */
		set_of_numbers_type get_hits ( set_of_numbers_type hits_ ) const;

		/* ! Return a vector < spot_type > with the spots the player has picked so far .
		@return The vector < spot_type > with the player ’s spots picked so far . */
		set_of_numbers_type get_spots ( void ) const;


		//A insertion sort algorithm.
		void insert_sort ();


		/*! Prints a table with payout to the all possible hits
		   @param size Size at a player spot */
		void print_payout( size_t size );

		/* ! The fuction returns the payout rate. 
			@param size Size of the spot_
			@param hitsMatch Number of hits are correct 
			@return a float to the payout rate */
		float get_payout ( size_t size, number_type hitsMatch );

};

	

