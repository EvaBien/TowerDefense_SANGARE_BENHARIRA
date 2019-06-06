#pragma once

enum BuildingType{
  RADAR,
  WEAPON,
  STOCK,
};

class Building
{
public:

  Building(float x, float y);
  Building(BuildingType type, float x, float y);
  ~Building();

  void update(const char path[]);

  /* Getters */
  float getX() const { return m_x; }
  float getY() const { return m_y; }
  BuildingType getType() const { return m_type; }

  /* Setters */
  void setX(float x) { m_x = x; }
  void setY(float y) { m_y = y; }

private:
  float m_x;
  float m_y;
  float m_radius;
  BuildingType m_type;
};
