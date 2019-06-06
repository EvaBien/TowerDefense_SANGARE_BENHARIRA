#pragma once

#include <glm/glm.hpp>

class CatMonster {
public:
    CatMonster(float x, float y);
    ~CatMonster();

    void update();

    /* Getters */
    float getX() const { return m_x; }
    float getY() const { return m_y; }

    /* Setters */
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

private:
    float m_x;
    float m_y;
};