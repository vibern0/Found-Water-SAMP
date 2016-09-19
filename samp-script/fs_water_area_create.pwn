#include <a_samp>


enum e_build_area
{
	bool:building = false,
	Float:area_x[127],
	Float:area_y[127],
	pickup[127],
	vert_number
};
new player_build_area[e_build_area];


public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" fs_water_area loaded ");
	print("--------------------------------------\n");
	return 1;
}


public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/start_area", cmdtext, true, 11) == 0)
	{
	    if(IsPlayerAdmin(playerid))
	    {
	        SendClientMessage(playerid, -1, "You are not admin!");
	        return 1;
		}
		if(player_build_area[building] == true)
		{
		    SendClientMessage(playerid, -1, "You already started an area!");
	        return 1;
		}
		player_build_area[building] = true;
		player_build_area[vert_number] = 0;
		return 1;
	}
	else if (strcmp("/add_point", cmdtext, true, 10) == 0)
	{
		if(player_build_area[building] == false)
		{
		    SendClientMessage(playerid, -1, "You have not started an area yet!");
	        return 1;
		}
		if(player_build_area[vert_number] > 126)
		{
		    SendClientMessage(playerid, -1, "You cant use more vertices in this area!");
	        return 1;
		}
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		player_build_area[area_x][player_build_area[vert_number]] = x;
		player_build_area[area_y][player_build_area[vert_number]] = y;
		player_build_area[pickup][player_build_area[vert_number]] = CreatePickup(1318, 1, x, y, z, -1);
		player_build_area[vert_number] ++;
		return 1;
	}
	else if (strcmp("/remove_last_point", cmdtext, true, 18) == 0)
	{
	    if(player_build_area[building] == false)
		{
		    SendClientMessage(playerid, -1, "You have not started an area yet!");
	        return 1;
		}
		if(player_build_area[vert_number] == 0)
		{
		    SendClientMessage(playerid, -1, "There is no previous vertice!");
	        return 1;
		}
		player_build_area[vert_number] --;
		DestroyPickup(player_build_area[pickup][player_build_area[vert_number]]);
		return 1;
	}
	else if (strcmp("/finish_area", cmdtext, true, 11) == 0)
	{
	    if(player_build_area[building] == false)
		{
		    SendClientMessage(playerid, -1, "You have not started an area yet!");
	        return 1;
		}
		if(player_build_area[vert_number] == 0)
		{
		    SendClientMessage(playerid, -1, "There is nothing to save!");
	        return 1;
		}
		new str_out[32];
		new Float:x, Float:y;
		new File:handle = fopen("file_water_area.txt", io_write);
		if(handle)
		{
			fwrite(handle, "(");
			x = player_build_area[area_x][0];
		    y = player_build_area[area_y][0];
		    format(str_out, 32, "%.2f %.2f", x, y);
		    fwrite(handle, str_out);
			for(new i = 1; i < player_build_area[vert_number]; i++)
			{
			    x = player_build_area[area_x][i];
			    y = player_build_area[area_y][i];
			    format(str_out, 32, ", %.2f %.2f", x, y);
			    fwrite(handle, str_out);
			}
			fwrite(handle, ")");
			fclose(handle);
		}
		else
		{
			print("Failed to open file \"file_water_area.txt\".");
		}
		return 1;
	}
	return 0;
}

