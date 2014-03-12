#include <stdio.h>
#include <iostream>
using namespace std; 

#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <string>
#include <sstream>
#include "../common/imageloader.h"
#include "../texture/texture.h"
#include "../terrain/terrain.h"
#include "../objRender/modelRender.h"
#include "../objRender/glm.h"
#include "../physics/phy.h"
#include "../io/read.h"
#include "../io/highscore.h"
#include "../io/track.h"
#define MAXSPEED 100.0
#define PI 3.14159265
#define DT 0.025
GLuint _modelTexture1;
GLuint _modelTexture2;
GLuint _textureId1;
GLuint _textureId2,_texmed,_front,_texstop;
float x,z;
bool game=true;
GLMmodel *myModel;
Terrain* _terrain;
ball B;
int chs;
bool once=true;
bool anim=true;
obj object;
int oTIME,TIME;
bool flag=true;
char TERRAIN[30],TEXTURE[30],HSCORE[30],TRACKINFO[30];
bool hs=false;
bool keyPress[]={false,false,false,false};
void HUD(const int x, const int y,const int z,string text);
void drawHUD(float);
void Draw_Skybox(float x, float y, float z, float width, float height, float length);
float treeRatio=2.0;
void tree(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat angle,GLint n, GLint branchCount) {
    //!Draws the teleporter object
	glBegin(GL_LINE_STRIP);
    glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
    if(n<1)return ;
	int nn = n-1;      
   GLfloat x3=(x2-x1)*treeRatio+x1-x2, y3=(y2-y1)*treeRatio+y1-y2; 
	if(branchCount==2){
             tree(x2, y2, x3 * cos(angle) + y3 * sin(angle) + x2, -x3 * sin(angle) + y3 * cos(angle) + y2, angle, nn, branchCount);
             tree(x2, y2, x3 * cos(-angle) + y3 * sin(-angle) + x2, -x3 * sin(-angle) + y3 * cos(-angle) + y2, angle, nn, branchCount);
    }
 else { 
       GLfloat nowAngle = -angle; GLfloat angleTone = angle/(branchCount-1)*2; 
       for(int i=0;i<branchCount;i++,nowAngle+=angleTone){ 
	       tree(x2, y2, x3 * cos(nowAngle) + y3 * sin(nowAngle) + x2, -x3 * sin(nowAngle) + y3 * cos(nowAngle) + y2, angle,nn,branchCount); 
		   }
		   }
}

float _angle=0;
void drawMed(GLuint _pass);
void drawObj(obj o1){
		//!Draws the bonus markers
		/*!
			Type 0 is a +ve marker that increases the time by 5s and speed by 2 times.
		    Type 1 is a -ve marker that decreases the time by 25s and speed by 5 times.
		*/
		for (int i=0;i<o1.size;i++){
		glPushMatrix();
		glTranslatef(o1.x[i],_terrain->getHeight(o1.x[i],o1.z[i])+2,o1.z[i]);
		
		switch(o1.type[i]){
		case 0:
			//_angle1+=0.01;
			glColor3f(1,1,1);
			//glRotatef(_angle*4.0,0,1,0);
			//if (o1.dis[i]) glutSolidSphere(2,50,50);
			if (o1.dis[i]) drawMed(_texmed);
			break;
		case 1:
			//_angle2+=0.01;
			glColor3f(1,1,1);
			//glRotatef(_angle*4.0,0,1,0);
			if (o1.dis[i]) drawMed(_texstop);
			break;
		case 2:
			_angle+=5;
			glColor3f(1,0.5,0);
			
			glPushMatrix();
			glRotatef(_angle,0,1,0);
			if (o1.dis[i]) tree(0,0,0,1,50.0,2,20);
			glPopMatrix();
			break;
		default:break;
		}
		glPopMatrix();
		}
		glColor3f(1,1,1);
		
		 //cout<<"and"<<endl;
		 
		 }
void initRendering() {
	//!Sets up the inital perimeters
	/*!
	This part includes loading the textures into OpenGL, getting the heightmap into
	a usuable format (like the specifying x-z points)
	*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	Image* image = loadBMP("../bmpFiles/quad.bmp");
	_modelTexture1 = loadTexture(image);
	delete image;
	Image* image11 = loadBMP("../bmpFiles/quad2.bmp");
	_modelTexture2 = loadTexture(image11);
	delete image11;
	Image* image1 = loadBMP(TEXTURE);
	_textureId1 = loadTexture(image1);
	delete image1;
	myModel = glmReadOBJ("../objFiles/quad.obj");
	_terrain=loadTerrain(TERRAIN,40);
	Image* image2 = loadBMP("../bmpFiles/speed.bmp");
	_textureId2 = loadTexture(image2);
	delete image2;
	Image* image4 = loadBMP("../bmpFiles/front.bmp");
	_front = loadTexture(image4);
	delete image4;
	Image* image3 = loadBMP("../bmpFiles/med.bmp");
	_texmed = loadTexture(image3);
	delete image3;
	Image* image5 = loadBMP("../bmpFiles/stop.bmp");
	_texstop = loadTexture(image5);
	delete image5;
	
}


void drawMed(GLuint _pass){
    //!This function draws the +ve Bonus Marker and is also used for the Skybox
	glPushMatrix();
	glScalef(2,2,2);
    glBindTexture(GL_TEXTURE_2D, _pass);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	 // Render the front quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[0]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the left quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
    glEnd();
 
    // Render the back quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[2]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
 
    glEnd();
 
    // Render the right quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[3]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the top quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[4]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
        glTexCoord2f(0, 0); glVertex3f( -0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f,  0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();
 
    // Render the bottom quad
    //glBindTexture(GL_TEXTURE_2D, _skybox[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
        glTexCoord2f(0, 1); glVertex3f( -0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 1); glVertex3f(  0.5f, -0.5f,  0.5f );
        glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void render_skybox(){
//!Draws the skybox
glPushMatrix();
glScalef(1000,1000,1000);
glColor3f(1,1,1);
//glTranslatef((int)_terrain->width,0,(int)_terrain->length);
drawMed(_front);
glPopMatrix();
}
float ly;
void drawScene() {
//!Handles all drawing 
/*!
Everything from the skybox to the bike to the terrain and the markers are drawn and 
redrawn through this function with each frame
*/
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  gluPerspective(45.0,1.6,1.0,10000.0);
  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  render_skybox();
 GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
  Vec3f orient = B.direct;
  //cout<<B.direct[0]<<" "<<B.direct[1]<<" "<<B.direct[2]<<endl;
  glColor3f(1,1,1);
  //Draw_Skybox(256,256,0,1000,1000,1000);
  Vec3f cam=Vec3f(orient[0],0,orient[2]);
  cam.normalize(); 
  ly=B.center[1] +5;
  if (ly<(_terrain->getHeight((int)B.center[0],(int)B.center[2]))) ly=_terrain->getHeight((int)B.center[0],(int)B.center[2])+5;
  gluLookAt(B.center[0]-cam[0]*20,ly,B.center[2]- cam[2]*20,B.center[0],B.center[1],B.center[2],0,1,0);
  
  //object[0].drawObj();
  drawTerrain(_textureId1,_terrain);
  
  glPushMatrix();
	//	cout << B.center[0]<<" "<<B.center[1]<<" "<<B.center[2]<<endl;
		//cout<< B.center[0]-cam[0]*20<<" "<<B.center[1] +15<<" "<<B.center[2]- cam[2]*20<<endl;
		glTranslatef(B.center[0],B.center[1],B.center[2]);
		float phi = acos(orient[1]/orient.magnitude()) * 180 / PI ; 
		float theta = atan(orient[0]/orient[2]) * 180 / PI; 
		if(orient[2] < 0) theta += 180; 
		//glRotatef(phi-90,0,0,1); 
		//cout << theta << " "<< phi << " " << B.center[0]<<" "<<B.center[1]<<" "<<B.center[2]<<endl;
		glRotatef(theta,0,1,0); 
		glRotatef(phi - 90,1,0,0);
		int x=(int) B.speed;
		if (x>0) anim=!(anim);
		if (anim) drawModel(myModel,_modelTexture1);
		else drawModel(myModel,_modelTexture2);
		
  glPopMatrix();
  glPushMatrix();
  //cout<<TIME<<endl;
  drawObj(B.objects);
  drawHUD(B.speed);
  glPopMatrix();
  glutSwapBuffers();
}
int randi;
void update(int){
  //!Handles updates
  /*!
  This is the function which essentially handles the dynamics of our game,ie 
  how the fps varies.
  */
  if (flag){
  randi=rand()%10000;
  B.simulate(keyPress);
  for(int i=0;i<B.objects.size;i++){
  if (!(B.objects.dis[i]) && randi<10) {
  B.objects.dis[i]=true; 
  break;
  }
  }
  drawScene();
  }
  else if (once){
   once=false;
   int phs=getHighScore(HSCORE);
   cout<<"prev:"<<phs<<endl;
   chs=clock()-oTIME;
   cout<<"curr:"<<chs<<endl;
   if (chs>phs) {
   hs=true;
   putHighScore(HSCORE,chs);
  }
  }
  glutTimerFunc(25,update,1000*DT);
}
void handleResize(int w, int h) {
  //!Handles Resize of the GLUT Window
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (double)w / (double)h, 1.0, 1000.0);
}
void handleKeypress(unsigned char key,int x ,int y){
//! Handles normal keypresses
/*!
The Escape is mapped to the exit function 
And the ability to jump using space is defined here
*/
if (key==27) exit(0);
if (key==32) {
if (B.center[1]<_terrain->getHeight(B.center[0],B.center[2])+20)
{
B.vel+=Vec3f(0,4,0);
B.direct=B.vel.normalize();
B.speed=B.vel.magnitude();
}
}

 
}
void specialPress(int key, int x, int y){
	//!Handles Controls
	switch (key) {
		case GLUT_KEY_RIGHT:
				keyPress[3] = true;
				break;
		case GLUT_KEY_LEFT:
				keyPress[2] = true;
				break;
		case GLUT_KEY_UP:
				keyPress[0] = true;
				break;
		case GLUT_KEY_DOWN:
				keyPress[1] = true;
				break;
	}
}

void specialUp(int key,int x,int y){
	//!Handles Controls(while releasing a key)
	switch (key) {
		case GLUT_KEY_RIGHT:
				keyPress[3] = false;
				break;
		case GLUT_KEY_LEFT:
				keyPress[2] = false;
				break;
		case GLUT_KEY_UP:
				keyPress[0] = false;
				break;
		case GLUT_KEY_DOWN:
				keyPress[1] = false;
				break;
	}
}

int main(int argc, char** argv)
{
//!The main function executed so as to begin the GLUT rendering.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400,400);
  getTrackInfo(TERRAIN,TEXTURE,TRACKINFO,HSCORE);
  
  glutCreateWindow("Object Rendering");
  initRendering();
  //cout<<"here"<<endl;
  cout<<TRACKINFO;
  object=returnInfo((char*)(string(TRACKINFO)).c_str());  
  glutFullScreen();
 // object[0]=obj(80,-15,50,5,"cube",0);
  B = ball((*_terrain).w,(*_terrain).l,(*_terrain).hs,_terrain->normals,Vec3f(1,0,0),Vec3f(x,-50,z),0,object);
  glutDisplayFunc(drawScene);
  glutReshapeFunc(handleResize);
  glutKeyboardFunc(handleKeypress);
  glutSpecialFunc(specialPress);
  glutSpecialUpFunc(specialUp);
  TIME = clock();
  glutTimerFunc(25,update,0);
  glutMainLoop();
  }

void HUD(const int x, const int y,const int z,string text,int speed)
{
	//!Handles the HeadsUp Display
	/*!
	Displays the current position
	Displays the Speed as a speedometer and the value
	Displays the TIME LEFT 
	*/
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glColor3f(255,0,0);
	glRasterPos3f(8,8,10);
	for(int i=0;i<text.length();i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
	stringstream ss2,ss1,ss,ss3;
	ss1<<"SPEED: "<< speed;
	string abhi=ss1.str();
	glRasterPos3f(-9,8,10);
	for(int i=0;i<abhi.length();i++)
 		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, abhi[i]);
	ss2<<"X:"<<B.center[0]<<" Y:"<<B.center[1]<<" Z:"<<B.center[2];
	abhi=ss2.str();
	glRasterPos3f(-9,-8,10);
	for(int i=0;i<abhi.length();i++)
 		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, abhi[i]);
if (game) { 
 int time = 100000- clock() + TIME ;
	
 	time /= 1000;
	if (time>0){
		 
		 ss<<"TIME: " << time;
		string Time=ss.str();
		glRasterPos3f(0,8,10);
		for(int j=0;j<Time.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);

	}
	else{
		 ss<<"TIME: " << time;
		string Time=ss.str();
		glRasterPos3f(-1,8,10);
		for(int j=0;j<Time.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Time[j]);
		string str;
		ss3<<(clock()-oTIME);
		//cout<<chs<<endl;
		//cout<<hs<<endl;
		if (chs>=getHighScore(HSCORE)){
		str = string("New High Score!! ->");}
		else{ 
		str = string("GAME OVER ->  ");}
		str.append(" Your Score is: ");
		
		str.append(ss3.str());
		glRasterPos3f(-1,7,10);
		for(int j=0;j<str.length();j++)
 			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[j]);
		flag=false;
	}}
	
	float rad=1,len=0.1,r=PI/180;
	glTranslatef(0,-8,0);
	glScalef(2,2,2);
	glPushMatrix();
	glTranslatef(-1,-1,0);
	glScalef(2,1,1);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0,0);
	glVertex3f(0,0,0);
	glTexCoord2f(1,0);
	glVertex3f(1,0,0);
	glTexCoord2f(0,1);
	glVertex3f(0,1,0);
	glTexCoord2f(0,1);
	glVertex3f(0,1,0);
	glTexCoord2f(1,0);
	glVertex3f(1,0,0);
	glTexCoord2f(1,1);
	glVertex3f(1,1,0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glTranslatef(0,0,0.1f);
	glColor3f(1,0,0);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<=180;i+=5){
		glVertex3f(rad*cos(r*(i)),-1+rad*sin(r*(i)),0);
		if(i%10==0)
			len=0.2;
		if(i%40==0)
			len=0.3;
		if(i%10!=0 & i%40!=0)
			len=0.1;
		glVertex3f((rad-len)*cos(r*(i)),-1+(rad-len)*sin(r*(i)),0);
		glVertex3f(rad*cos(r*(i)),-1+rad*sin(r*(i)),0);
	}
	glVertex3f(rad,-1,0);
	glEnd();
	rad=0.9;
//	glColor3f(1,0,0);
	if (speed>MAXSPEED) speed=MAXSPEED;
	glBegin(GL_LINE_STRIP);
		glVertex3f(-0.05,-1,0);
		glVertex3f(rad*cos(r*(180-(180/MAXSPEED)*speed)),-1+rad*sin(r*(180-(180/MAXSPEED)*speed)),0);
		glVertex3f(0.05,-1,0);
	glEnd();
}
void drawHUD(float speed){
   //!Loads the HUD into the GLUT Window
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10,10,-10,10,-10,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   HUD(0,0,10,"SAVE THY!",speed);
}
