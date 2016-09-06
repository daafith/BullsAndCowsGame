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

	const FString HIDDEN_WORD = "and"; // const because reference
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString) {

	return false;
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
				// if in the same place -->increment bulls
				// if in the word but different place --> increment bulls
		}
	}


	return BullCowCount;
}

