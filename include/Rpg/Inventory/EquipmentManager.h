#pragma once

#include "rpg/items/Armor.h"
#include "rpg/inventory/ArmorInventory.h"

namespace rpg::inventory
{

struct EquipmentSlots
{
  items::ArmorPtr head{};
  items::ArmorPtr body{};
  items::ArmorPtr hands{};
  items::ArmorPtr legs{};
};

class EquipmentManager
{
public:
  [[nodiscard]] const EquipmentSlots& getSlots() const { return slots_; }
  void equipArmor(int id, ArmorInventory& armorInventory);
  void unequipArmor(items::ArmorType slot, ArmorInventory& armorInventory);

private:
  EquipmentSlots slots_{};
};

} // namespace rpg::inventory
