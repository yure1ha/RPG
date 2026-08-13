#include "Rpg/Items/Weapon.h"

#include "Rpg/Items/Item.h"

#include <string>
#include <utility>

namespace Rpg::Items
{

Weapon::Weapon(ItemAttributes attr, WeaponStats stats)
    : Item {withDefaults(std::move(attr), ItemType::weapon, 1)},
      stats_ {stats}
{
}

} // namespace Rpg::Items
