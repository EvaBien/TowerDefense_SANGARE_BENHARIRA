
#include "../include/building.hpp"

#ifdef _WIN32
#include <windows.h>
#endif
#define _USE_MATH_DEFINES
#include <cmath>
#include <glad/glad.h>
#include <stdio.h>

Building::Building(float x, float y) : m_x(x),m_y(y), m_radius(100){
  printf("New Building Created ! \n");
}

Building::Building(BuildingType type, float x, float y)
{
  this->m_x=x;
  this->m_y=y;
  this->m_type=type;
  if (this->m_type == RADAR){
    this->m_radius=100;
    printf("New Radar Building created ! \n");
  } else if (this->m_type == WEAPON){
    this->m_radius=75;
    printf("New Weapon Building created ! \n");
  } else if (this->m_type == STOCK){
    this->m_radius=50;
    printf("New Stock Building created ! \n");
  }
}

Building::~Building() {
    printf("Building destructed ! \n");
}

void Building::update() {
    glColor4f(255, 255, 0, 1);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
        glVertex2f(m_x, m_y);
    glEnd();
    glPointSize(1.0f);

	// Draw collision circle
	float segments = 16.0f;
	float increment = 2.0f * M_PI / segments;
	float theta = 0.0f;

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < segments; i++) {
		float x = m_x + m_radius * cos(theta);
		float y = m_y + m_radius * sin(theta);
		glVertex2f(x, y);
		theta += increment;
	}
	glEnd();
}
