#pragma once

#include "FBullCowGame.h"


// Getters
int32 FBullCowGame::GetCurrentTry() const { return MycurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
bool FBullCowGame::IsGameWon() const {	return bGameIsWon;}
EGuessStatus FBullCowGame::checkValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Length_error;
	}
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	



	return EGuessStatus::OK;
}
int32 FBullCowGame::GetHiddenWordLength() const  // returns the length of the hiddend word
{
	return MyHiddenWord.length();
}



void FBullCowGame::reset()
{
	constexpr int32 MAX_TRIES = 5;
	MycurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";

	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

}


// reuturns a valid guess and increment turns and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{	
	MycurrentTry++;
	// set up a return variable 
	FBullCowCount BullCowCount;
	
	
	int32 WordLengh = MyHiddenWord.length(); // assuming that the word is of same length as guess
	

	for (int32 MHWchar = 0; MHWchar < WordLengh; MHWchar++) {
		// compare letter against the hidden word
			for(int32 Gchar=0; Gchar< WordLengh; Gchar++){
			// if the match then
				if (MyHiddenWord[MHWchar] == tolower(Guess[Gchar])) {
					// if they are in the same place
					if (MHWchar == Gchar) {
						BullCowCount.Bulls++; // incremet bulls
					}
					else {
						BullCowCount.Cows++;// increment cows
					}
				}

			}
	}
	if (BullCowCount.Bulls == WordLengh) {
		bGameIsWon = true;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) // null of 1 letter string are also considered as an isogram 
	{
		return true;
	}
	Tmap <char, bool> LetterSeen;

	for (auto letter : Word) // for all letter in Word 
	{
		letter = tolower(letter);
		if (LetterSeen[letter]) { return false; } // we do not have an isogram 
		else
		{
			LetterSeen[letter] = true;
		}



	}


	return true;
}

