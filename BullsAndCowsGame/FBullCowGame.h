#pragma once
#include <string>
class FBullCowGame { //Unreal naming convention
public:
	FBullCowGame();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO: make better return value
	bool CheckGuessValidity(std::string); //TODO: make better return value


private:
	// see constructor for initialisation
	int MyCurrentTry;
	int MyMaxTries;
};

