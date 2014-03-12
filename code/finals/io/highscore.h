#ifndef INCLUDED_HIGHSCORE_H
#define INCLUDED_HIGHSCORE_H
#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std; 

int getHighScore(char* name){
//!Retrieving the high scores from the specified file 
	fstream f(name);
	int x;
	f >> x; 
	f.close();
	return x; 
}

void putHighScore(char* name,int score){
//!Writing the highscore into the specified file
	fstream f(name);
	f << score ; 
	f.close();
}

#endif