#include "Point.hpp"

float crossProduct(float x1, float y1, float x2, float y2) {
    return x1 * y2 - y1 * x2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    float   vAB[2] = {b.getX() - a.getX(), b.getY() - a.getY()};
    float   vBC[2] = {c.getX() - b.getX(), c.getY() - b.getY()};
    float   vCA[2] = {a.getX() - c.getX(), a.getY() - c.getY()};
    float   vPA[2] = {point.getX() - a.getX(), point.getY() - a.getY()};
    float   vPB[2] = {point.getX() - b.getX(), point.getY() - b.getY()};
    float   vPC[2] = {point.getX() - c.getX(), point.getY() - c.getY()};
    if (crossProduct(vAB[0], vAB[1], vPA[0], vPA[1]) < 0) return false;
    if (crossProduct(vBC[0], vBC[1], vPB[0], vPB[1]) < 0) return false;
    if (crossProduct(vCA[0], vCA[1], vPC[0], vPC[1]) < 0) return false;
    return true;
}