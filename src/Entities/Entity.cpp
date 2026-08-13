#include "rpg/entities/Entity.h"

#include <algorithm>
#include <utility>

namespace rpg::entities
{

Entity::Entity(EntityAttributes entityAttr) : entityAttr_{std::move(entityAttr)}
{
}

std::string Entity::getEntityTypeName(const EntityType type)
{
  switch (type)
  {
  case EntityType::Character:
    return "Character";

  case EntityType::Enemy:
    return "Enemy";

  case EntityType::NPC:
    return "NPC";

  default:
    return "Unknown";
  }
}

void Entity::clampHealth()
{
  entityAttr_.currentHealth =
      std::clamp(entityAttr_.currentHealth, 0, getMaxHealth());
}

void Entity::takeDamage(const int amount)
{
  entityAttr_.currentHealth -= amount;
  clampHealth();
}

void Entity::heal(const int amount)
{
  entityAttr_.currentHealth += amount;
  clampHealth();
}

void Entity::healToMax() { entityAttr_.currentHealth = getMaxHealth(); }

} // namespace rpg::entities
