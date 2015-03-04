/********************************************************
 * Filename: functions.h
 * Author: Tara Massey
 * Date: 01/15/2015
 *
 * Purpose: Declare additonal functions
 *
*********************************************************/

#ifndef MASSEYTA_FUNCTIONS_H
#define MASSEYTA_FUNCTIONS_H


#include<iostream>
#include<string>

using std::string;

int displayMenu();

bool switchValidation(string userChoice);

bool coordValidation(string row, string col);

bool iterationsValidation(string times);

void displayOscillator();

void displayGlider();

void displayGun();

void addLines();

#endif

