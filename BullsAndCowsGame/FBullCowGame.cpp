#include "stdafx.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const 
{
	return false;
}

void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8; // constant expr because literal
	const FString HIDDEN_WORD = "foobar"; // const because reference

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}


EWordStatus FBullCowGame::CheckGuessValidity(FString) const 
{

	return EWordStatus::OK;  // TODO make status depend on validity
}

// counts bulls and cows and increases try #, assumes valid guess
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HiddenWordCharacter = 0; HiddenWordCharacter < HiddenWordLength; HiddenWordCharacter++) {
		// loop through the guess
		for (int32 GuessCharacter = 0; GuessCharacter < HiddenWordLength; GuessCharacter++) {
			// loop through the hidden word
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


	return BullCowCount;
}

