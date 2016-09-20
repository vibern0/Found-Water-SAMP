#ifndef WATER_H
#define WATER_H

#define INVALID_WATER_AREA_ID		-1

int add_water_area(char* area);
bool remove_water_area(int id);
bool point_in_water_area(int area_id, float x, float y);
bool point_in_any_water_area(float x, float y);
int get_water_area_by_point(float x, float y);

#endif