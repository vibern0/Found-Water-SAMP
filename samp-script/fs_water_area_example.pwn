#include <a_samp>
#include "../include/water_area"

new water_area_lake;

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print("          Water Area Example");
	print("--------------------------------------\n");
	//
	water_area_lake = AddWaterArea("(482.08 -1496.08, 487.51 -1496.05, 489.12 -1489.41, 481.39 -1487.65)");
	return 1;
}

public OnFilterScriptExit()
{
    RemoveWaterArea(water_area_lake);
	return 1;
}

public OnPlayerUpdate(playerid)
{
	if(IsPlayerInAnyArea(playerid))
	{
	    printf("playerid : %d in water area!", playerid);
	}
	return 1;
}
