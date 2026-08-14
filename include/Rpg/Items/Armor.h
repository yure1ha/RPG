#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/DefenseComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"


namespace Rpg
{

class Armor
{
public:
  Armor(IdComponent id,
        DefenseComponent defense,
        StatusModifierComponent modifier)
      : m_id {id},
        m_defense {defense},
        m_modifier {modifier} {}

  IdComponent id() const { return m_id; }

private:
  IdComponent m_id;

  DefenseComponent m_defense;
  StatusModifierComponent m_modifier;
};

} // namespace Rpg
