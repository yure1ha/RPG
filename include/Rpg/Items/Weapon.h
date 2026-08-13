#pragma once

#include "Rpg/Items/Item.h"

#include <memory>
#include <string>

namespace Rpg::Items
{

enum class WeaponType
{
  melee,
  ranged,
};

struct WeaponStats
{
  WeaponType type {};

  int attack {};
  int currentDurability {};
  int maxDurability {};
};

class Weapon : public Item
{
public:
  Weapon(ItemAttributes attr, WeaponStats stats);

  [[nodiscard]] WeaponStats getStats() const { return stats_; }
  [[nodiscard]] bool isUsable() const { return stats_.currentDurability > 0; }

private:
  WeaponStats stats_ {};
};

using WeaponUPtr = std::unique_ptr<Weapon>;

} // namespace Rpg::Items
