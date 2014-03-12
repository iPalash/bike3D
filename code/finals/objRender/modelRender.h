#ifndef MODELRENDER_H_INCLUDED
#define MODELRENDER_H_INCLUDED

#include <iostream>
#include "glm.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


void drawModel(GLMmodel* glmodel, GLuint _textureId){
//!The function draws the specified model along the texturing it with the specified texture.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < glmodel->numpolygons; i++)
	{
		GLMpolygon poly = glmodel->polygons[i];
		int numver = poly.numvertices;
    for(int j = 0; j < numver; j++)
    {
      int vi = poly.vindices[j];
      if (1==poly.t) { int ti = poly.tindices[j];
      glTexCoord2f(glmodel->texcoords[2*ti],glmodel->texcoords[2*ti + 1]);}
      glVertex3f(glmodel->vertices[3*vi],glmodel->vertices[3*vi+1],glmodel->vertices[3*vi+2]);
    }
  }
glEnd();
glDisable(GL_TEXTURE_2D);
}


#endif