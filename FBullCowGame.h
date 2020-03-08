#pragma once
#include <string>
#include <map>
#define Tmap std::map
using FString = std::string;
using int32 = int;



struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Length_error,

};


class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();
	// getter functions
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus checkValidity(FString) const; //TODO make a more richer return value


	void reset();
	

	// provide a method for counting the number of bull & cows , increment the Current_try.
	FBullCowCount SubmitValidGuess(FString);

private:// dont expose variables publically
	int32 MycurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const; 
};

inline FBullCowGame::FBullCowGame()
{
	MycurrentTry = 1;
	MyMaxTries = 5;
}

 inline FBullCowGame::~FBullCowGame()
{
}

