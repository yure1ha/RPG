#include "rpg/inventory/ArmorInventory.h"

#include "rpg/items/Armor.h"

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

namespace rpg::inventory
{

void ArmorInventory::sortArmorInventory()
{
  std::ranges::stable_sort(armorInventory_,
                           [](const auto& a, const auto& b)
 {
   if (a->getArmorType() != b->getArmorType())
   {
     return a->getArmorType() < b->getArmorType();
   }

   return a->getDefense() < b->getDefense();
 });
}

items::Armor* ArmorInventory::searchArmorInventory(const int id) const
{
  for (const auto& item : armorInventory_)
  {
    if (item->getId() == id) { return item.get(); }
  }

  return nullptr;
}

void ArmorInventory::addArmor(items::ArmorPtr armor)
{
  if (!armor) return;

  armorInventory_.push_back(std::move(armor));
  sortArmorInventory();
}

items::ArmorPtr ArmorInventory::removeArmor(const items::Armor* armor)
{
  if (!armor) return nullptr;

  const auto it = std::ranges::find_if(armorInventory_,
      [armor](const items::ArmorPtr& a) { return a.get() == armor; });

  if (it == armorInventory_.end()) return nullptr;

  items::ArmorPtr removed{std::move(*it)};
  armorInventory_.erase(it);

  return removed;
}

} // namespace rpg::inventory
