#include "rpg/entities/Character.h"

#include "rpg/entities/Entity.h"

#include <string>

namespace rpg::entities
{

Character::Character(const EntityAttributes& entityAttr,
                     const CharacterAttributes& characterAttr)
    : Entity{entityAttr}, characterAttr_{characterAttr}
{
}

std::string Character::getCharacterTypeName(const CharacterType type)
{
  switch (type)
  {
  case CharacterType::Warrior:
    return "Warrior";

  case CharacterType::Sorcerer:
    return "Sorcerer";

  case CharacterType::Deprived:
    return "Deprived";

  default:
    return "Unknown";
  }
}

int Character::getMaxHealth() const { return characterAttr_.vitality; }

int Character::getMaxEquipLoad() const { return characterAttr_.endurance; }

int Character::getCurrentEquipLoad() const { return 0; }

double Character::getEquipLoadRatio() const
{
  return static_cast<double>(getCurrentEquipLoad()) / getMaxEquipLoad();
}

} // namespace rpg::entities
