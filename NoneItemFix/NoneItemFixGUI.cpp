#include "pch.h"
#include "NoneItemFix.h"

std::string NoneItemFix::GetPluginName() {

	return "None Item Popup Fix";
}

void NoneItemFix::SetImGuiContext(uintptr_t ctx) {

	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

void NoneItemFix::RenderSettings() {

	if (ImGui::Button("Load Freeplay")) {

		gameWrapper->Execute([this](GameWrapper* gw) { cvarManager->executeCommand("load_freeplay"); });
	}

	if (ImGui::IsItemHovered()) {

		ImGui::SetTooltip("In case you are stuck at the main menu :)");
	}
}