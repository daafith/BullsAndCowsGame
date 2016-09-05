#pragma once
#include <string>
using FString = std::string; // FString is mutable
using int32 = int;

class FBullCowGame { //Unreal naming convention
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make better return value
	bool CheckGuessValidity(FString); //TODO make better return value
	// provde a method for counting bulls and cows and increasing try #

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
};

