#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include <string>
#include "../common/vec3f.h"
#include "../objRender/glm.h"
#include "../texture/texture.h"
#include "../common/imageloader.h"
#include "../terrain/terrain.h"

class obj {
//!This is a class pertaining to all the types of interactive objects placed on the track.
	public:
		int size; // No of objects 
		float *x; 
		float *z; //specifying their position
		bool *dis;
		int *type; //specifying the type 
		obj(){}
		obj(int num){
			size=num;
			x=new float[num];
			z=new float[num];
			type=new int[num];
			dis=new bool[num];
			
			}
		//draws all of them on the terrain . 
		void drawObj(Terrain* _terrain){
		glPushMatrix();
		for (int i=0;i<size;i++){
		glTranslatef(x[i],_terrain->getHeight(x[i],z[i])+2,z[i]);
		switch(type[i]){
		case 0:
			glColor3f(1,0,0);
			if (dis) glutSolidSphere(2,50,50);
			break;
		case 1:
			glColor3f(0,1,0);
			if (dis) glutSolidSphere(2,50,50);
			break;
		case 2:
			glColor3f(0,0,1);
			if (dis) glutSolidSphere(2,50,50);
			break;
		default:break;
		}
		
		}
		glColor3f(1,1,1);
		
		 //cout<<"and"<<endl;
		 glPopMatrix();
		 }
};			























#endif