#pragma once

#include "Rpg/Inventory/Inventory.h"
#include "Rpg/Items/Weapon.h"

namespace Rpg::Inventory
{

class WeaponInventory : public Inventory<Items::Weapon>
{
public:
  void sortWeaponInventory();
};

} // namespace Rpg::Inventory
