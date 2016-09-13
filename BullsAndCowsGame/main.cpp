﻿/* main.cpp : Defines the entry point for the console application.
Uses the BullCow class and acts as the view in a MVC pattern.
*/

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; //create alias , FText is immutable

void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; // create the instance

int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

void PrintIntro() 
{
	BCGame.Reset(); // moved here instead of playgame because the constructor is called twice the first time // TODO find solution to potential bug
	std::cout << "\n\n";
	std::cout << "###############################################\n";
	std::cout << "# Welcome to Bulls and Cows, a fun word game! #\n";// << endl instead is OK
	std::cout << "#    ( _____ )                :_____:         #\n";
	std::cout << "#    ^( * * )^               ^( * * )^        #\n";
	std::cout << "#      ( 0 )                   ( + )          #\n";
	std::cout << "#        -                       -            #\n";
	std::cout << "###############################################\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
}

void PlayGame() 
{
//	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have " << MaxTries << " tries in total.\n\n";
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry <<  " of " << BCGame.GetMaxTries();
		std::cout << ". Please enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter isogram.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (a word without recurring letters).\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter an isogram in lower case.\n\n";
			break;
		default:
			//assuming it's a valid guess
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Well done champ, you guessed the isogram!\n";
	}
	else {
		std::cout << "Game over, better luck next time!\n";
	}
}

bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


