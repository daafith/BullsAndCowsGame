#pragma once
#include <string>
using FString = std::string; // FString is mutable
using int32 = int;

// all values are zero
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame { //Unreal naming convention
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make better return value
	bool CheckGuessValidity(FString); //TODO make better return value
	BullCowCount SubmitGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};

