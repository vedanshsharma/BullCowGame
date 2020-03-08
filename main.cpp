#include <iostream>

#include "FBullCowGame.h"





void printIntro();
void PlayGame();
FString  GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game

void printGameSummary();



// entry point of the game
int main()
{
 
	bool bPlayAain = true;
	do
	{
		BCGame.reset();
		printIntro();
		PlayGame();
		bPlayAain = AskToPlayAgain();
		std::cout << "\n\n";
	} while (bPlayAain);
	std :: cout << std :: endl;
	return 0;
}


void printIntro()
{
	std :: cout << "Welcome to Bulls and Cows" << std :: endl;
	std :: cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I`m thinking of?" << std :: endl ;
	return;
}
void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		
		std::cout << "attempt number " << BCGame.GetCurrentTry() <<std :: endl;
		FString  guess = GetValidGuess(); // check validity of the guess



		std::cout << "Your guess is : " << guess << std::endl;
		// submit calide guesses to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);
		// print the number of bulls and cows
		std::cout << "Bulls =" << BullCowCount.Bulls;
		std::cout << " Cows =" << BullCowCount.Cows<< "\n\n";
		
		
	}
	//  summarise the game
	printGameSummary();

}
FString  GetValidGuess()

{
	FString  guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		std::cout << "Enter your guess : ";
		getline(std::cin, guess);
		Status = BCGame.checkValidity(guess);
		switch (Status) {
		case(EGuessStatus::Length_error):
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word" << "\n";
			break;
		case(EGuessStatus::Not_Isogram):
			std::cout << "Please enter a vaid isogram" << "\n";
			break;
		default:
			// the guess is valid
			break;
		}
		std::cout << std::endl;
	}while(Status != EGuessStatus ::OK); // keep looping until we get no errors
	return guess;
}
bool AskToPlayAgain()
{
	std :: cout << "Do you want to play again[y/n]?";
	FString  Response;
	getline(std :: cin,Response);
	if (tolower(Response[0]) == 'y')
	{
		return true;
	}
	return false;
}

void printGameSummary()
{
	if ( !BCGame.IsGameWon()) {
		std::cout << "Better luck next time" << "\n";
	}
	else {
		std::cout << "BINGO! You guessed it correctly" << "\n";
	}
}


