#include "Rpg/Inventory/WeaponInventory.h"

#include "Rpg/Inventory/Inventory.h"
#include "Rpg/Items/Weapon.h"

namespace Rpg::Inventory
{

void WeaponInventory::sortWeaponInventory()
{
  sort([](const Items::WeaponUPtr& a, const Items::WeaponUPtr& b)
  {
    if (a->getStats().type != b->getStats().type)
    {
      return a->getStats().type < b->getStats().type;
    }

    if (a->getStats().attack != b->getStats().attack)
    {
      return a->getStats().attack > b->getStats().attack;
    }

    return a->getAttr().instanceId < b->getAttr().instanceId;
  });
}

} // namespace Rpg::Inventory
