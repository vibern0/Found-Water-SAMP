#ifndef WATER_H
#define WATER_H

#define INVALID_WATER_AREA_ID		-1

int add_water_area(char* area);
bool remove_water_area(int id);
bool point_in_any_water_area(float x, float y);

#endif