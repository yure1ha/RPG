#pragma once

#include "rpg/items/Armor.h"

#include <memory>
#include <vector>

namespace rpg::inventory
{

class ArmorInventory
{
public:
  using Container = std::vector<items::ArmorPtr>;

  [[nodiscard]] const Container& getArmorInventory() const
  {
    return armorInventory_;
  };

  void sortArmorInventory();
  [[nodiscard]] items::Armor* searchArmorInventory(int id) const;
  void addArmor(items::ArmorPtr armor);
  items::ArmorPtr removeArmor(const items::Armor* armor);

private:
  Container armorInventory_{};
};

} // namespace rpg::inventory
