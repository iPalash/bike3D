#ifndef INCLUDED_TRACK_H
#define INCLUDED_TRACK_H
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
extern bool game;
using namespace std; 

void getTrackInfo(char* terrain,char* texture,char* info,char* hs){
//!This function provides us with the files containing the data about the terrain, trackData and score info.
	fstream f("../dataFiles/trackID.txt"); 
	int x;
	f >> x; 
	f >>game;
	string temp="../bmpFiles/tracks/xh.bmp";
	for(int i=0;i<temp.length();i++)terrain[i]=temp[i];
	terrain[temp.length()]='\0';
	temp="../bmpFiles/tracks/xt.bmp";
	for(int i=0;i<temp.length();i++)texture[i]=temp[i];
	texture[temp.length()]='\0';
	temp="../dataFiles/obstacles/x.txt";
	for(int i=0;i<temp.length();i++)info[i]=temp[i];
	info[temp.length()]='\0';
	temp="../dataFiles/highscore/x.txt";
	for(int i=0;i<temp.length();i++)hs[i]=temp[i];
	hs[temp.length()]='\0';
	texture[19]= x+'0';
	info[23]=x+'0';
	hs[23]=x+'0';
	terrain[19] = x+'0'; 
	f.close();
	 
}
#endif