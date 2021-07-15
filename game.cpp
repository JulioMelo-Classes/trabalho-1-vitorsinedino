#include "KenoBet.h"

/*! Generate 20 random numbers to a round with shuffling the ordened vector with elements [1, 80].
	@return numberSet_t vector with 20 random numbers. */
set_of_numbers_type lottery()
{

	//Creating a simple vector.
	set_of_numbers_type list_hit;
			
	//Storing sequentials (1 ~ 80) values in list_hit.
	for ( auto i(0); i < 80; ++i)
	{
		list_hit.push_back( i+1 ); 
	}

	//Obtained a time-based seed.
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//Shuffling the values in vector.
	std::shuffle ( list_hit.begin(), list_hit.end(), std::default_random_engine(seed) );

	//Resizing the vector, to pick up only the first twenty random numbers.
	list_hit.resize( 20 );

	//Return the random generated vector.
	return list_hit;

}

/*
Avaliação
Processamento do Arquivo de Entrada: 0,3 (faltou o o caso quando o arquivo tem menos de 3 linhas, segfault quando tem mais de 15 numeros na aposta, ignora, mas não dá erro quando tem numeros repetidos, caracteres estranhos e letras)
Execução correta: 0,6 (segfault com 15 números)
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 0 (não fez)  
Organização em src, include, build, data: 0 (não fez)

Comentários
- Eu esperava ao menos mais um arquivo com funções fora o kenobet.h/cpp, no entanto a maioria das funcionalidades
está implementada aqui. Uma sugestão seria vc fazer um arquivo para interface textual e outro pra processar o arquivo
de entrada.
- Embora dê segfault quando eu uso 15 numeros (pois você está endereçando errado a tabela de payout), a maior
parte da implementação está ok
- Vi que você implementou o insertion sort, mas foi algo meio pontual e dependente da classe KenoBet, usualmente era
de se esperar que você já tivesse a ciencia para separar essa parte de ordenação em um arquivo(h e cpp) separado.
- Para o próximo trabalho sugiro que invista na compilação automatica usando makefile ou cmake(recomendado)
*/

int main ( int argc, char * argv[] )
{
	
	std::cout << ">>> Preparing to read bet file [" << argv[1] << "], please wait...\n";
	std::cout << "----------------------------------------------------------------\n";
	
	//Declarating a istream object type.
	std::ifstream file;
	//Opening the file.
	file.open(argv[1]);
	
	if(file)
	{ 
		//Declarations of the variables.

		std::string word;
		
		size_t i;
		size_t size;
		size_t round;
		size_t total_round;


		set_of_numbers_type bet;
		set_of_numbers_type random_n;
		set_of_numbers_type hit_spot;

		cash_type wage;
		cash_type round_wage;
		cash_type round_pay;
		cash_type final_money;

		number_type totalHitsMatch;

		//Class object
		KenoBet player;
		
		i = 0;
		while( file >> word )
		{
			if( i == 0 )
			{
				player.set_wage( std::stod( word ) );
				++i;
			}

			else if(i == 1)
			{
				total_round = std::stoi( word );
				++i;
			}

			else
			{
				/* @brief Breaking the last line in numbers, and allocating in the bet vector 
							of the player. */
				std::stringstream iss( word );

				number_type number;
				while ( iss >> number ){
					player.add_number( number );
				}
			}

		}

		// If the number of elements readed is more than 20, just pick the 20º firsts.
		// currently not working
		if( player.size() > 20 ){
			size = 20;
		}else{
			size = player.size();
		}

		//Ordener the vector with insertion sort algorithm.
		player.insert_sort();
		
		//Getting the values of player.
		bet = player.get_spots();
		wage = player.get_wage();

		round_wage = wage / total_round;

		player.print_payout( size );
		final_money = wage;

		for ( round = 1; round <= total_round; ++round ) 
		{
			cash_type payout_rate;
			std::cout << " ----------------------------------------------------------------------------------- \n "<< std::endl;
			std::cout << " >>> Table of payouts <<< \n" << std::endl;

			std::cout << "    ------------------------------------------------------------\n";
			std::cout << "    This round #" << round << " of " << total_round << ", and your wage is $" << round_wage << ". Good luck!\n";
			
			//Randon draw
			random_n = lottery();
			
			// Printing a list of than 20 random numbers.
			std::cout << "    The hits are: [";
			for( i = 0; i < random_n.size(); ++i )
			{
				std::cout << random_n[ i ] << " ";
			}
			std::cout << "]\n";
			std::cout << std::endl;

			//Printing your bet.
			std::cout << "    You bet is the following number(s) ["; 
			for ( i = 0; i < size; ++i )
			{
				std::cout << " " << bet[ i ] << " ";
			}
			std::cout << "]\n";
			std::cout << std::endl;

			//Printing a list of numbers who matched with the random generated numbers.
			hit_spot = player.get_hits( random_n );
			std::cout << "    You hit the following number(s) ["; 
			for( i = 0; i < hit_spot.size(); ++i ){
				std::cout << " " << hit_spot[ i ] << " ";
			}


			// Calculating a int number to the size of vector of hits matched at the spots.
			totalHitsMatch = hit_spot.size();

			//Calculating the gain in this round.
			payout_rate = player.get_payout( bet.size() , totalHitsMatch );
			round_pay =  round_wage * payout_rate;

			//Calculating your new wage after the final of actual round.
			final_money = ( final_money - round_wage ) + round_pay;




			std::cout << "], a total of " << totalHitsMatch << " hit(s) out of " <<  hit_spot.size() << ".\n";
			std::cout << "    Payout rate is " << payout_rate << ", thus you came out with: $" << round_pay << ".\n";
			std::cout << "    Your net balance so far is: $" << final_money << " dollar(s).\n";
		}


		std::cout << ">>> End of rounds!\n";
		std::cout << "----------------------------------------------------------------\n";

		std::cout << std::endl;

		std::cout << "===== SUMMARY =====\n";
		std::cout << ">>> You spent in this game a total of $" << player.get_wage() << " dollar(s).\n";
		std::cout << ">>> Hooray, you won $" << final_money - player.get_wage() << " dollar(s). See you next time!\n";
		std::cout << ">>> You are leaving the Keno table with $" << final_money << " dollar(s).\n";

		std::cout << std::endl;
		

	} 

	else
	 
	{
	
		std::cout << " >>>Invalid bet format<<< \n" ;
		std::cout << ">>> Couldn't open the bet file\n";
		std::cout << std::endl;

	}

	file.close();

	return 0;

}
