#ifndef PHY_H_INCLUDED
#define PHY_H_INCLUDED
#include "../common/vec3f.h"
#include <iostream>
#include <cmath>
#define DOWN Vec3f(0,-1,0)
#define DT 0.025
#define GRAV 100
#define ACC 50
#define EPS 0.1
#define ALPHA 0.1
#include "collision.h"
#include "stdlib.h"
extern int TIME;
using namespace std;
class ball{
//!Handles the physics of the moving bike
public:
	int width,length;
	float **hs; 
	obj objects;
	Vec3f **normal; 
	Vec3f center, direct, vel;
	float speed,approxRad;
	
	ball(){}
	
	ball(int _width ,int _length,float** &_hs,Vec3f** &_normals,Vec3f _direct,Vec3f _center,float _speed,obj _objects){
	width = _width; 
	length = _length; 
	hs = _hs; 
	normal = _normals; 
	center = _center; 
	direct = _direct; 
	speed = _speed; 
	objects=_objects;
	approxRad=2.0f;
	
}
	
	void restrict(){
	if(center[0] < EPS)vel[0] = -vel[0] , center[0] = 2*EPS; 
	if(center[2] < EPS)vel[2] = - vel[2], center[2] = 2*EPS; 
	if(center[0]  + EPS > length)vel[0] = -vel[0] , center[0] = length - 2*EPS; 
	if(center[2]  + EPS > width)vel[2] = - vel[2] , center[2] = width - 2*EPS; 
}


Vec3f getNormal(){
	return normal[(int)center[2]][(int)center[0]].normalize(); 
}
float getHeight(){
	return hs[(int)center[2]][(int)center[0]]; 
}
void simulate(bool isPressed[4]){
	vel = direct.normalize() * speed; 
	Vec3f norm1 = getNormal();
	
	Vec3f prevCenter(center[0],center[1],center[2]); 
	Vec3f newCenter = center + vel * DT; 
	
	 
	center = newCenter; 
	checkCollision(prevCenter);
	restrict(); 
	
	if(center[1] < getHeight())center[1] = getHeight() ; 
	
	if(center[1] > getHeight() + EPS)
	{  //IN AIR
		vel = vel + DOWN * GRAV * DT;
		speed=vel.magnitude();
		direct=vel.normalize();
		if(isPressed[0]){
			vel = vel + direct*ACC*DT; 
		}
		if(isPressed[1]){
			vel = vel - vel.normalize()*ACC*DT; 
		}
		if(isPressed[3]){
			float x = direct[0];
			float z = direct[2]; 
			direct[0] = x * cos(ALPHA)-z*sin(ALPHA);
			direct[2] = z * cos(ALPHA)+x*sin(ALPHA);
		}
		if(isPressed[2]){
			float x = direct[0];
			float z = direct[2]; 
			direct[0] = x * cos(ALPHA)+z*sin(ALPHA);
			direct[2] = z * cos(ALPHA)-x*sin(ALPHA);
		}
		
		vel=speed*0.99*direct;
		
		if(vel.magnitude() != 0)direct = vel.normalize(); 
	}
	else{ //ON GROUND 
		direct = direct - direct.dot(norm1)*norm1; 
		direct = direct.normalize(); 
		vel = vel + DOWN.project(direct) * GRAV * DT; 
		vel = vel.project(direct);
		if(isPressed[0]){
			vel = vel + direct*ACC*DT; 
		}
		if(isPressed[1]){
			vel = vel - vel.normalize()*ACC*DT; 
		}
		if(isPressed[3]){
			float x = direct[0];
			float z = direct[2]; 
			direct[0] = x * cos(ALPHA)-z*sin(ALPHA);
			direct[2] = z * cos(ALPHA)+x*sin(ALPHA);
		}
		if(isPressed[2]){
			float x = direct[0];
			float z = direct[2]; 
			direct[0] = x * cos(ALPHA)+z*sin(ALPHA);
			direct[2] = z * cos(ALPHA)-x*sin(ALPHA);
		}
		direct = direct - direct.dot(norm1)*norm1; 
		direct = direct.normalize();
		speed = vel.magnitude() * 0.98; 
		vel = direct * speed; 
	}
}
	void checkCollision(Vec3f prevCenter){
		int i=0;
		float e=0.0f;
		float x_rand,z_rand;
		while(i<objects.size){
		
		obj temp=objects;
		
		i++;
		Vec3f tt=Vec3f((temp.x[i-1]),(hs[(int)(temp.z[i-1]+2)][(int)temp.x[i-1]]),temp.z[i-1]);
		
		Vec3f norm=center-tt;
		//cout<<norm.magnitude()<<endl;
		if (norm.magnitude()<(2+approxRad)&&temp.dis[i-1]){
			//We have a collision;
			//cout<<"here"<<endl;
		/*center=prevCenter;
			norm=norm.normalize();
			vel=vel -(1+e)*vel.dot(norm)*norm;
			if (vel.magnitude()!=0) direct=vel.normalize();
			break; */
			objects.dis[i-1]=false;
			switch(temp.type[i-1]){
			case 0:
					speed*=2;
					vel=direct*speed;
					TIME+=5000;
					
					break;
			case 1:
					speed/=5;
					vel=direct*speed;
					TIME-=25000;
					break;
			case 2: 
					x_rand=rand()%width;
					z_rand=rand()%length;
					center=Vec3f(x_rand,hs[(int)z_rand][(int)x_rand],z_rand);
					break;
			default:break;
			}
		}
		
		}
		
	}
};




#endif