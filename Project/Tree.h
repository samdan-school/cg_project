#if !defined(TREE_H)
#define TREE_H
#include "w_constant.h"
#include "residence.h"
void draw_tree(){
    glPushMatrix();
    glTranslatef(-250,0,-390);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_BLEND);
    glRotatef(-90,1,0,0);
    glScalef(1.5,1.5,1.5);
    draw_face(tree1_faces, tree1_colorInfo, tree1_colors, tree1_num);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}
#endif 