#include "Localization.hpp"
#include <unordered_map>
#include <string>
#include <string_view>
namespace YimMenu::Localization {
static const std::unordered_map<std::string_view, std::string_view> kExact = {
 {"Self","自己"},{"Vehicle","载具"},{"Teleport","传送"},{"Network","网络"},{"Players","玩家"},{"World","世界"},{"Recovery","恢复"},{"Settings","设置"},{"Debug","调试"},
 {"Home","主页"},{"Dashboard","仪表盘"},{"General","常规"},{"Misc","杂项"},{"Weapons","武器"},{"Weapon","武器"},{"Ammo","弹药"},{"Money","金钱"},
 {"Enabled","已启用"},{"Disabled","已禁用"},{"Enable","启用"},{"Disable","禁用"},{"Active","活动"},{"Inactive","未激活"},
 {"Add","添加"},{"Delete","删除"},{"Remove","移除"},{"Clear","清除"},{"Close","关闭"},{"Open","打开"},{"Save","保存"},{"Load","加载"},{"Apply","应用"},{"Reset","重置"},{"Back","返回"},{"Cancel","取消"},{"Confirm","确认"},{"Refresh","刷新"},{"Search","搜索"},{"Filter","筛选"},{"Select","选择"},{"Current","当前"},{"Default","默认"},{"Custom","自定义"},{"All","全部"},{"None","无"},{"Unknown!","未知！"},
 {"Categories","分类"},{"Category","分类"},{"Name","名称"},{"Description","描述"},{"Type","类型"},{"Value","数值"},{"Amount","数量"},{"Count","数量"},{"Index","索引"},{"Size","大小"},{"Distance","距离"},{"Speed","速度"},{"Position","位置"},{"Rotation","旋转"},{"Color","颜色"},{"Colors","颜色"},{"Scale","缩放"},
 {"Hotkey","快捷键"},{"Clear","清除"},{"Current","当前"},{"Saved...","已保存……"},{"Chat","聊天"},{"Challenges","挑战"},{"Casino","赌场"},{"Bounty","悬赏"},
};
std::string Translate(std::string_view text) { auto it=kExact.find(text); if(it!=kExact.end()) return std::string(it->second); return std::string(text); }
}
