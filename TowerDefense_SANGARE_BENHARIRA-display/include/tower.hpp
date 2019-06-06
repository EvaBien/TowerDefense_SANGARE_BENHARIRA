#pragma once

enum TowerType{
  RED_LASER,
  GREEN_GRASS,
  YELLOW_GAMMELLE,
  BLUE_MILK,
};

class Tower
{
public:
  Tower(float x, float y);
  Tower(TowerType type, float x, float y);
  ~Tower();

  void update(const char path[]);

  /* Getters */
  float getX() const { return m_x; }
  float getY() const { return m_y; }
  TowerType getType() const { return m_type; }

  /* Setters */
  void setX(float x) { m_x = x; }
  void setY(float y) { m_y = y; }

private:
  float m_x;
  float m_y;
  float m_radius;
  TowerType m_type;
};
