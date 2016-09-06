#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {

	return false;
}

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 8; // constant expr because literal
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet"; // const because reference
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString) {

	return false;
}

// counts bulls and cows and increases try #, assumes valid guess
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;


	return BullCowCount;
}

