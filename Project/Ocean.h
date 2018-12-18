#if !defined(OCEAN_H)
#define OCEAN_H
#include "w_constant.h"
#include "residence.h"
void draw_water_face(vector<Face> &face, vector<Color> &color_info, vector<string> &colors, vector<int> &num) {
	glBegin(GL_TRIANGLES);
	int i=0;
	float normal[3];
	for(int l = 0; l < colors.size(); l++){
		for (const Color &color : color_info) {
			if(color.name == colors[l]){
				
				glColor4f(color.r, color.b, color.g, 0.55);
				for(int s = 0; s < num[l]; s++){

					calcNormal(face[i], normal);
					glNormal3fv(normal);
					
					for (int j = 0; j < 3; ++j){
						
						glVertex3f(2*face[i].v[j].x, 2*face[i].v[j].y, 2*face[i].v[j].z);
					}
				
					i++;
				}
			}
		}
	}
	glEnd();
}
void draw_water(float t){

vector<Face> f1;
float zz = -40;
float xx = -20;
for(int i=0; i< water_faces.size(); i++){
	float x1=water_faces[i].v[0].x+zz;
	float y1=water_faces[i].v[0].y;
	float z1=water_faces[i].v[0].z+xx;
	Vertex temp1(x1,y1,z1);
	float x2=water_faces[i].v[1].x+zz;
	float y2=water_faces[i].v[1].y;
	float z2=water_faces[i].v[1].z+xx;
	Vertex temp2(x2,y2,z2);
	float x3=water_faces[i].v[2].x+zz;
	float y3=water_faces[i].v[2].y;
	float z3=water_faces[i].v[2].z+xx;
	Vertex temp3(x3,y3,z3);
	Face temp4(temp1, temp2, temp3);
	f1.push_back(temp4);
}
vector<Face> f2;
for(int i=0; i< water_faces.size(); i++){
	float x1=water_faces[i].v[0].x*t+(1-t)*f1[i].v[0].x;
	float y1=water_faces[i].v[0].y*t+(1-t)*f1[i].v[0].y;
	float z1=water_faces[i].v[0].z*t+(1-t)*f1[i].v[0].z;
	Vertex temp1(x1,y1,z1);
	float x2=water_faces[i].v[1].x*t+(1-t)*f1[i].v[1].x;
	float y2=water_faces[i].v[1].y*t+(1-t)*f1[i].v[1].y;
	float z2=water_faces[i].v[1].z*t+(1-t)*f1[i].v[1].z;
	Vertex temp2(x2,y2,z2);
	float x3=water_faces[i].v[2].x*t+(1-t)*f1[i].v[2].x;
	float y3=water_faces[i].v[2].y*t+(1-t)*f1[i].v[2].y;
	float z3=water_faces[i].v[2].z*t+(1-t)*f1[i].v[2].z;
	Vertex temp3(x3,y3,z3);
	Face temp4(temp1, temp2, temp3);
	f2.push_back(temp4);
}
	glPushMatrix();
	glTranslatef(-200, 0, -650);
	glScalef(20.0,1,2);
	glRotatef(-90, 1, 0, 0);
   	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	draw_water_face(f2, water_colorInfo, water_colors, water_num);
	glDisable(GL_BLEND);
	glPopMatrix();

}

#endif 



