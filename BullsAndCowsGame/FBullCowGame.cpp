/*Fleshes out the details of the bull / cow game.*/
#pragma once
#include "stdafx.h"
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FString FBullCowGame::GetHiddenWord() const 
{
	FString HiddenWords[] = {"vet", "ant", "pun", "pen", "bug", "fun", "link", "rain", "wait", "nerd", "bird", "train"};
	int32 Word = rand() % (sizeof(HiddenWords) / sizeof(*HiddenWords)); // need to explain this to myself, is perhaps too psuedo random
	return HiddenWords[Word];
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries = { {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset() 
{
	MyHiddenWord = GetHiddenWord();
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// implemented defensively: no implicit dependencies so the order of the decision can be changed without breaking implementation
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{
	if (!IsIsoGram(Guess)) { 
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	} 
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	} 
	return EGuessStatus::OK;
}

bool FBullCowGame::IsIsoGram(FString Guess) const
{
	if (Guess.length() <= 1) { return true; } 
	TMap<char, bool> LetterSeen;
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		} 
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}

// counts bulls and cows and increases try #, assumes valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength();

	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < WordLength; HiddenWordCharacter++) {
		for (int32 GuessCharacter = 0; GuessCharacter < WordLength; GuessCharacter++) {
			if (Guess[GuessCharacter] == MyHiddenWord[HiddenWordCharacter]) {
				if (HiddenWordCharacter == GuessCharacter) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLength()) { 
		bGameIsWon = true; 
	}
	return BullCowCount;
}
