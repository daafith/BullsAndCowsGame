#pragma once
#include <string>
using FString = std::string; // FString is mutable
using int32 = int;

//Unreal naming convention
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

//Unreal naming convention
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

//Unreal naming convention
class FBullCowGame 
{ 
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 

	void Reset(); //TODO make better return value
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsoGram(FString) const;
	bool IsLowerCase(FString) const;
};

