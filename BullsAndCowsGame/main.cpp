// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n"; // << endl instead is OK
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
}


void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	cout << "You have " << MaxTries << " attempts in total" << endl;

	for (int i = 1; i <= MaxTries; i++) {
		string Guess = GetGuess();
		cout << "You typed: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	cout << "Try " << CurrentTry << ". Please enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

}


