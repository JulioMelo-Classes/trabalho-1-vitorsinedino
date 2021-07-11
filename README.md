#KENOBET_GAME
DESCRIPTION
This project has been developed to the discipline of PL I ( Programming Language I ) of a IT Graduation at UFRN-Brasil. The game consists in a player choose 1 ~ 15 numbers between [1, 80], and bet his choise, shuffling your initial wage in each round played. To be played is necessary a archive with the parameters of a players (The archive are be described in the next topic).


COMPILING AND RUNNING
To compile this code is necessary c++11 or superior compiler. In this case had been utilizated the g++ 6.2.0 in a Ubuntu 16.10.
	1. In terminal, open the folder, after that writes the command "g++ -Wall -std=c++11 game.cpp KenoBet.cpp -o game" and press Enter.
	2. After that writes the command "./game 'default-bet.txt'". (You should have an archive with tree lines, the first line consists in a Money value to your wage, the second line consists in a number of rounds to be played, and the third line consists in a sequence of numbers, separated by white spaces, to be bet).


BUILT WITH 
The language is C++ version 11.

LICENSE
This project is licensed under the MIT License.