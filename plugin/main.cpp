#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

typedef void(*logprintf_t)(char* format, ...);

#include "water.h"

logprintf_t logprintf;
extern void *pAMXFunctions;


cell AMX_NATIVE_CALL AddWaterArea(AMX* amx, cell* params)
{
	int len = 0, ret = 0;
	cell *addr = nullptr;

	amx_GetAddr(amx, params[1], &addr);
	amx_StrLen(addr, &len);

	if (len)
	{
		len++;
		
		char* text = new char[len];
		amx_GetString(text, addr, 0, len);
		
		ret = add_water_area(text);

		logprintf("New water area added!");

		delete[] text;
	}

	return (cell)ret;
}

cell AMX_NATIVE_CALL RemoveWaterArea(AMX* amx, cell* params)
{
	//
	return 1;
}

cell AMX_NATIVE_CALL PointInAnyWaterArea(AMX* amx, cell* params)
{
	float x, y;
	x = amx_ctof(params[1]);
	y = amx_ctof(params[2]);

	return (cell)point_in_any_water_area(x, y);
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf(" * Found-Water-SAMP plugin Loaded *");
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf(" * Found-Water-SAMP plugin Unloaded *");
}

AMX_NATIVE_INFO PluginNatives[] =
{
	{ "AddWaterArea", AddWaterArea },
	{ "RemoveWaterArea", RemoveWaterArea },
	{ "PointInAnyWaterArea", PointInAnyWaterArea },
	{ 0, 0 }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, PluginNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}