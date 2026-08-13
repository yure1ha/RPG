#include "Rpg/Items/Armor.h"

#include "Rpg/Items/Item.h"

#include <string>
#include <utility>

namespace Rpg::Items
{

Armor::Armor(ItemAttributes attr, ArmorStats stats)
    : Item {withDefaults(std::move(attr), ItemType::armor, 1)},
      stats {stats}
{
}

} // namespace Rpg::Items
