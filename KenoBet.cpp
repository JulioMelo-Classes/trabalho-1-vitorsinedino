#include "KenoBet.h"
	

// ! Creates an empty Keno bet .
KenoBet::KenoBet() 
{
	set_wage(0);	
};
/* ! Adds a number to the spots only if the number is not already there .
	@param spot_ The number we wish to include in the bet .
	@return T if number chosen is successfully inserted ; F otherwise . */
bool KenoBet::add_number ( number_type spot_ )
{	
	if ( spot_ >= 1 && spot_ <= 80 )
	{

			if ( std::find( m_spots.begin(), m_spots.end(), spot_ ) == m_spots.end() )
			{
				m_spots.push_back( spot_ );
				return true;
			}

	} 
	return false;

}

/* ! Sets the amount of money the player is betting .
	@param wage_ The wage .
	@return True if we have a wage above zero ; false otherwise . */
bool KenoBet::set_wage ( cash_type wage_ )
{
	if ( wage_ > 0.0 )
	{
		m_wage = wage_;
		return true;
	}
	else 
	{
		return false;
	}
}


// ! Resets a bet to an empty state .
void KenoBet::reset ( void ) 
{
	m_spots.clear();
}
		

/* ! Retrieves the player ’s wage on this bet .
	@return The wage value . */
cash_type KenoBet::get_wage ( void ) const
{
	return m_wage;
}
		
// C O N S E R T A R !
/* !Returns to the current number of spots in the player’s bet .
	@return Number of spots present in the bet . */
size_t KenoBet::size ( void ) const
{
	// <! vector::size method default.
	return m_spots.size();
}


/* ! Determine how many spots match the hits passed as argument .
	@param hits_ List of hits randomly chosen by the computer .
	@return An vector with the list of hits . */
set_of_numbers_type KenoBet::get_hits ( set_of_numbers_type hits_ ) const
{	
	size_t i;
	set_of_numbers_type list_hit;
	
	//std::find(m_spots.begin(), m_spots.end(), spot) != m_spots.end();
	for(i = 0; i < m_spots.size(); ++i)
	{
		if( std::find( hits_.begin(), hits_.end(), m_spots[i] ) != hits_.end() )
		{
			list_hit.push_back(m_spots[i]);
		}
	}
	return list_hit;

}


/* ! Return a vector < spot_type > with the spots the player has picked so far .
	@return The vector < spot_type > with the player ’s spots picked so far . */
set_of_numbers_type KenoBet::get_spots ( void ) const
{
	return m_spots;
}



void KenoBet::insert_sort ( )
{
	auto hole ( 0ul );

	for ( auto i(1ul); i < m_spots.size(); ++i )
	{	
		hole = i - 1;
		auto aux( m_spots[ i ] );
		while ( hole >= 0 &&  m_spots[ hole ] > m_spots[ i ] )
		{
			m_spots [ hole + 1] = m_spots [ hole ];
			--hole;
		}

		m_spots [ hole + 1 ] = aux;
	}

}


/* Prints a table with payout to the all possible hits */
void KenoBet::print_payout( size_t spots_ )
{
	for( auto i(0ul); i <= spots_; ++i )
	{
		//Just for alignment of the table.
		if( i < 10 )
		{
			std::cout << "            " << i << "   |   " << get_payout ( spots_ - 1, i ) << " \n";
		}
		else
		{
				std::cout << "           " << i << "   |   " <<  get_payout ( spots_ - 1, i ) << " \n";
		}

	}
		
}

/* ! The fuction returns the payout rate. 
	@param size Size of the spot_ */
cash_type KenoBet::get_payout ( size_t size, number_type hitsMatch ) 
{
	return payout_table[ size ][ hitsMatch ];
}


