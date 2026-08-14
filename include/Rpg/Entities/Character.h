#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/HealthComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"

#include "Rpg/Components/ActiveModifiersComponent.h"

#include "Rpg/Items/Consumable.h"
#include "Rpg/Items/Weapon.h"
#include "Rpg/Items/Armor.h"

#include "Rpg/Components/ContainerComponent.h"


namespace Rpg
{

class Character
{
public:
  Character(IdComponent id,
            HealthComponent health,
            StrengthComponent strength,
            DefenseComponent defense,
            ActiveModifiersComponent modifiers,
            ContainerComponent<Consumable> consumables,
            ContainerComponent<Weapon> weapons,
            ContainerComponent<Armor> armor)
      : m_id {id},
        m_health {health},
        m_strength {strength},
        m_defense {defense},
        m_modifiers {modifiers},
        m_consumables {consumables},
        m_weapons {weapons},
        m_armor {armor} {}

  IdComponent id() const { return m_id; }

private:
  IdComponent m_id;

  HealthComponent m_health;
  StrengthComponent m_strength;
  DefenseComponent m_defense;

  ActiveModifiersComponent m_modifiers;

  ContainerComponent<Consumable> m_consumables;
  ContainerComponent<Weapon> m_weapons;
  ContainerComponent<Armor> m_armor;
};

} // namespace Rpg
