#include "Onboarding.hpp"
#include "GUI.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/AnticheatBypass.hpp"
#include "game/pointers/Pointers.hpp"
#include <shellapi.h>

namespace YimMenu
{
	static BoolCommand _OnboardingComplete{"$onboardingcomplete", "", ""};

	void ProcessOnboarding()
	{
		if (_OnboardingComplete.GetState())
			return;

		static bool ensure_popup_open = [] {
			ImGui::OpenPopup("重要！请阅读！");
			GUI::SetOnboarding(true);
			return true;
		}();

		const auto window_size = ImVec2{700, 500};
		const auto window_position = ImVec2{(*Pointers.ScreenResX - window_size.x) / 2, (*Pointers.ScreenResY - window_size.y) / 2};

		ImGui::SetNextWindowSize(window_size, ImGuiCond_Once);
		ImGui::SetNextWindowPos(window_position, ImGuiCond_Once);

		if (ImGui::BeginPopupModal("重要！请阅读！", nullptr, ImGuiWindowFlags_NoSavedSettings))
		{
			ImGui::TextWrapped("%s",
			    "Welcome to YimMenuV2! You can press INSERT or Ctrl+\\ to open the menu. With the introduction of BattlEye, the ability to join and stay in public sessions has been severely limited. "
			    "你可以选择只与其他 YimMenu 用户一起游戏，也可以选择连接到普通的 BattlEye 保护战局。"
			    "进入普通战局后，你会在三分钟内被自动踢出，并且可能会被暂时列入黑名单，禁止"
			    "加入战局，最长可能持续两天，即使重新启用 BattlEye 也可能如此");
			static int value = 0;
			ImGui::RadioButton("与 YimMenu 用户一起游戏", &value, 0);
			ImGui::SameLine();
			ImGui::RadioButton("与所有人一起游戏（已损坏！）", &value, 1);
			ImGui::TextWrapped("%s",
			    "你随时可以在“网络 > 伪装 > 仅加入 YimMenu 用户战局”中切换此选项。我们的官方仓库位于 "
			    "https://github.com/YimMenu/YimMenuV2. Make sure to only download the menu from GitHub to avoid malware. "
			    "你可以通过仓库报告 Bug、提出功能建议并提交 Pull Request 来参与项目。我们还提供了一个 "
			    "Matrix server that can be found at https://matrix.to/#/#yimmenu:matrix.org for faster communication with developers "
			    "以及其他用户交流。Matrix 是 Discord 的免费开源替代方案，注册账户安全且简单");
			if (ImGui::Button("打开 GitHub"))
			{
				ShellExecuteA(NULL, "open", "https://github.com/YimMenu/YimMenuV2", NULL, NULL, SW_SHOWNORMAL);
			}
			ImGui::SameLine();
			if (ImGui::Button("打开 Matrix 服务器"))
			{
				ShellExecuteA(NULL, "open", "https://matrix.to/#/#yimmenu:matrix.org", NULL, NULL, SW_SHOWNORMAL);
			}
			ImGui::TextWrapped("%s",
			    "定期检查更新；我们每晚都会发布新版本。但最重要的是，尽情折腾 YimMenu，玩得开心！");
			if (ImGui::Button("关闭"))
			{
				Commands::GetCommand<BoolCommand>("cheaterpool"_J)->SetState(!value);
				_OnboardingComplete.SetState(true);
				GUI::SetOnboarding(false);
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
	}
}