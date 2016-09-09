#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8; // constant expr because literal
	const FString HIDDEN_WORD = "fozbar"; // const because reference

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{
	if (false) { // no isogram (not implemented yet)
		return EGuessStatus::Not_Isogram;
	}
	else if (false) { // not lowercase (not implemented yet)
		return EGuessStatus::Not_Lowercase;
	} 
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	} 
	return EGuessStatus::OK;

}

// counts bulls and cows and increases try #, assumes valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength();

	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < WordLength; HiddenWordCharacter++) {
		// loop through the letters of hidden word
		for (int32 GuessCharacter = 0; GuessCharacter < WordLength; GuessCharacter++) {
			// loop through the letters of guess and compares
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

