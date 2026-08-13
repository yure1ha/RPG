#include "rpg/inventory/EquipmentManager.h"

#include "rpg/items/Armor.h"
#include "rpg/inventory/ArmorInventory.h"

#include <utility>

namespace rpg::inventory
{

void EquipmentManager::equipArmor(const int id, ArmorInventory& armorInventory)
{
  const items::Armor* armor{armorInventory.searchArmorInventory(id)};
  if (!armor) return;

  items::ArmorPtr newArmor{armorInventory.removeArmor(armor)};
  if (!newArmor) return;

  items::ArmorPtr oldArmor{};

  switch (armor->getArmorType())
  {
  case items::ArmorType::Head:
    oldArmor = std::move(slots_.head);
    slots_.head = std::move(newArmor);
    break;

  case items::ArmorType::Body:
    oldArmor = std::move(slots_.body);
    slots_.body = std::move(newArmor);
    break;

  case items::ArmorType::Hands:
    oldArmor = std::move(slots_.hands);
    slots_.hands = std::move(newArmor);
    break;

  case items::ArmorType::Legs:
    oldArmor = std::move(slots_.legs);
    slots_.legs = std::move(newArmor);
    break;

  default:
    armorInventory.addArmor(std::move(newArmor));
    return;
  }

  if (oldArmor)
  {
    armorInventory.addArmor(std::move(oldArmor));
  }

}

void EquipmentManager::unequipArmor(const items::ArmorType slot, ArmorInventory& armorInventory)
{
  items::ArmorPtr removedArmor{};

  switch (slot)
  {
  case items::ArmorType::Head:
    removedArmor = std::move(slots_.head);
    break;

  case items::ArmorType::Body:
    removedArmor = std::move(slots_.body);
    break;

  case items::ArmorType::Hands:
    removedArmor = std::move(slots_.hands);
    break;

  case items::ArmorType::Legs:
    removedArmor = std::move(slots_.legs);
    break;
  }

  if (removedArmor)
  {
    armorInventory.addArmor(std::move(removedArmor));
  }
}

} // namespace rpg::inventory
