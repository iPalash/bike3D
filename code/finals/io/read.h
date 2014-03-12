#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED

#include <cstdio>
#include <fstream>
#include <string>
#include "../physics/collision.h"
#include "../terrain/terrain.h"

//!Setting the position of the bike
extern float x;
extern float z;


obj returnInfo(char* name){
//!This function returns the position and type of all the objects (bonuses,slow points and trans points) 
	fstream f(name);
	int n;
	f>>x;
	f>>z;
	f>>n;
	obj place(n); 
	for(int i=0;i<n;i++){
		f >>place.x[i]>>place.z[i]>>place.type[i]>>place.dis[i];
	}
	return place; 
}


#endif