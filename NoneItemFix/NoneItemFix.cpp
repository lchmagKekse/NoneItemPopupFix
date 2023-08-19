#include "pch.h"
#include "NoneItemFix.h"


BAKKESMOD_PLUGIN(NoneItemFix, "NoneItemFix", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void NoneItemFix::onLoad() {

	_globalCvarManager = cvarManager;

	gameWrapper->HookEventWithCallerPost<ServerWrapper>("Function TAGame.GFxData_MultiItemDrops_TA.GetUnseenContainerDrops", [this](ServerWrapper caller, void* params, std::string eventname) { GetUnseenContainerDropsHook(params); });
}

void NoneItemFix::onUnload() {}

void NoneItemFix::GetUnseenContainerDropsHook(void* params) {

	auto pStruct = (GetUnseenContainerDropsParams*)(params);
	if (!pStruct) return;

	std::vector<int32_t> validHashes;

	for (auto& hash : pStruct->ReturnValue) {

		if (hash == 0) continue;
		validHashes.push_back(hash);
	}

	pStruct->ReturnValue.clear();

	for (auto& hash : validHashes) {
		pStruct->ReturnValue.push_back(hash);
	}
}