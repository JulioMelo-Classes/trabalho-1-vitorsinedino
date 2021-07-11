
# Keno-Bet

Keno-bet is a keno game made with c++

## Compilation

1. In terminal "cd" into the project folder, after that write the command 

```bash
g++ -Wall -std=c++11 game.cpp KenoBet.cpp -o game
```
 and press Enter.
## Usage
You should have an .TXT with tree lines, the first line consists on your wage money, the second line consists of the number of rounds to be played, and the third line in a sequence of numbers separated by white spaces to be bet.

there is a default-bet.txt file inside the project folder
2. run the comand
```
./game 'default-bet.txt'
```

## License
[MIT](https://choosealicense.com/licenses/mit/)