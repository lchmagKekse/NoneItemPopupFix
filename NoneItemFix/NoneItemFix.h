#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "TArray.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

struct GetUnseenContainerDropsParams {

	TArray<int32_t> ReturnValue;
};

class NoneItemFix: public BakkesMod::Plugin::BakkesModPlugin {

	virtual void onLoad();
	virtual void onUnload();

	void GetUnseenContainerDropsHook(void* params);
};

