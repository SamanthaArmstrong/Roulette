/******************************************************************************
 Title:      Roulette Simulation      
 Programmer: Samantha Armstrong     
 Course:     CSCI 240     
 Instructor: Prof. Ringenberg     
 Due Date:   September 30, 2014     

 Description:	This Program will simulate a roulette game. The user will be able 
					to bet on what number the ball landed on, according to even 
					numbers, odd numbers, the first half, the second half, or an 
					exact number. The user will start with 1000 chips and can keep
					playing until the chips run out or they want to quit.

Input:			The user will input the following:
					- Which bet they want to place
					- How many chips they want to wager
					- Whether or not they want to continue with the current wager
					- Whether or not they want to play again

Output:			The program will output the following
					- A welcome message at the beginning of the program
					- The possible bets and the probability of each in a table
					- The user's selection of what they want to bet
					- Asks the user if they want to continue
					- The number the ball landed on
					- The results of their bet
					- The number of chips they have left
******************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

int main() {
	//Variables
	string		betType;
	int			chips = 1000;
	int			menu;
	int			wager;
	int			winningNum;
	int			exact;
	char		playAgain = 'Y';
	char		continueGame;
	const int	EXACT_PAYOUT = 35;
	
	//seed the random number generator
	srand((unsigned)time(0));

	// Welcome message to user at beginning of each game
	cout << "Welcome to Sam's Roulette Simulator!" << endl;
	cout << endl;
	cout << "Let's Play Roulette!" << endl;
	cout << endl;

	while (toupper(playAgain) == 'Y' && (chips > 0)){
		//Random number generator
		winningNum = rand() % 37;

		//Print out possible wagers and payouts
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl;
		cout << "| Payout | Wager                              |" << endl;
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl;
		cout << "| 1 to 1 | Even numbers ( 2,  4,  6, ..., 35) |" << endl;
		cout << "| 1 to 1 | Odd numbers  ( 1,  3,  5, ..., 36) |" << endl;
		cout << "| 1 to 1 | 1st half     ( 1,  2,  3, ..., 18) |" << endl;
		cout << "| 1 to 1 | 2nd half     (19, 20, 21, ..., 36) |" << endl;
		cout << "|35 to 1 | Exact guess                        |" << endl;
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << endl;

		//Wager selection menu
		cout << "[1] Even" << endl;
		cout << "[2] Odd" << endl;
		cout << "[3] 1st half" << endl;
		cout << "[4] 2nd half" << endl;
		cout << "[5] Exact" << endl;
		cout << endl;

		cout << "Select your wager: " << endl;
		cin  >> menu;
		cout << endl;

		while (menu < 0 || menu > 5){
			cout << "Invalid entry. Try again: " << endl;
			cin  >> menu;
		}

		switch (menu){
			case 1: // Even
				betType = "Evens";
				break;
			case 2: // Odd
				betType = "Odds";
				break;
			case 3: // 1st half
				betType = "The first half";
				break;
			case 4: // 2nd half
				betType = "The second half";
				break;
			case 5: // Exact
				betType = "The exact number";
				break;
		}//end switch menu 1
	
		cout << "You have " << chips << " chips." << endl;
		cout << endl;
		cout << "How many chips do you want to wager?" << endl;
		cin  >> wager;
		cout << endl;
	
		while (chips < wager){
			cout << "You don't have enough chips, try again:" << endl;
			cin  >> wager;
		} //end while chips error

		//continue?
		cout << "You have decided to wager " << wager << " chips on " << betType;
		cout << endl;

		cout << "Is this correct?" << endl; 
		cout << "Enter 'Y' to proceed with the game" << endl;
		cout << "OR enter 'N' to take back your wager: " << endl;
		cin  >> continueGame;
		cout << endl;

		if (toupper(continueGame) == 'Y'){ 
			switch (menu){
				case 1: //Even
					cout << "The ball landed on number " << winningNum << endl;
					if (winningNum % 2 == 0 && winningNum != 0){ 
						chips = chips + wager;
						cout << "You win " << wager << " chips!" << endl;	
					}
					else{
						chips = chips - wager;
						cout << "You lost " << wager << " chips." << endl;
					}
					break;
				case 2: //Odd
					cout << "The ball landed on number " << winningNum << endl;
					if (winningNum % 2 == 1 && winningNum != 0){ 
						chips = chips + wager;
						cout << "You win " << wager << " chips!" << endl;
					}
					else{
						chips = chips - wager;
						cout << "You lost " << wager << " chips." << endl;
					}
					break;
				case 3: //1st half
					cout << "The ball landed on number " << winningNum << endl;
					if (winningNum <= 18 && winningNum != 0){
						chips = chips + wager;
						cout << "You win " << wager << " chips!" << endl;
					}
					else{
						chips = chips - wager;
						cout << "You lost " << wager << " chips." << endl;
					}
					break;
				case 4: //2nd half
					cout << "The ball landed on number " << winningNum << endl;
					if (winningNum >= 19){
						chips = chips + wager;
						cout << "You win " << wager << " chips!" << endl;
					}
					else{
						chips = chips - wager;
						cout << "You lost " << wager << " chips." << endl;
					}
					break;
				case 5: //Exact
					cout << endl;
					cout << "Which number would you like to bet on?" << endl;
					cin  >> exact;
					cout << endl;

					while (exact < 0 || exact > 36){
						cout << "Error: Please enter a number between 0 and 36" << endl;
						cin  >> exact;
					} //end while

					cout << "The ball landed on number " << winningNum << endl;
					if (winningNum == exact){
						chips = chips + (chips * EXACT_PAYOUT);
						cout << "You win " << wager << " chips!" << endl;
					}
					else{
						chips = chips - wager;
						cout << "You lost " << wager << " chips." << endl;
					}
				break;	
			} //end switch case
			cout << "Now you have " << chips << " chips." << endl;
			cout << endl;
		}// end if continue game

		//Play again?
		cout << "Do you want to play again?" << endl;
		cin  >> playAgain;

	}// end while play again

	if (chips > 0){
		cout << endl;
		cout << "Congratulations! You walked away with " << chips << " chips!" << endl;
	}
	else{
		cout << endl;
		cout << "You lost all of your chips. Tough break, kid." << endl;
	}

	cout << "Thanks for playing!" << endl;

return 0;

}// end main