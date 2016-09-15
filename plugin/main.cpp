#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

typedef void(*logprintf_t)(char* format, ...);

#include "water.h"

logprintf_t logprintf;
extern void *pAMXFunctions;


cell AMX_NATIVE_CALL AddWaterArea(AMX* amx, cell* params)
{
	//
	return 1;
}

cell AMX_NATIVE_CALL RemoveWaterArea(AMX* amx, cell* params)
{
	//
	return 1;
}

cell AMX_NATIVE_CALL PointInWaterArea(AMX* amx, cell* params)
{
	//
	return 1;
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
	{ "PointInWaterArea", PointInWaterArea },
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