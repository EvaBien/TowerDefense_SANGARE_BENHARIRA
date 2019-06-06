#include "../include/catMonster.hpp"

#include <glad/glad.h>

CatMonster::CatMonster(float x, float y) : m_x(x), m_y(y) {
    // printf("CatMonster created ! \n");
}

CatMonster::~CatMonster() {
    // printf("CatMonster destructed !\n");
}

void CatMonster::update() {
    glColor4f(255, 0, 0, 1);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2f(m_x, m_y);
    glEnd();
    glPointSize(1.0f);
}
