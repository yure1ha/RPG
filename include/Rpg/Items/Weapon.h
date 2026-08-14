#pragma once

#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/Attributes/StrengthComponent.h"
#include "Rpg/Components/StatusModifierComponent.h"

namespace Rpg
{

class Weapon
{
public:
  Weapon(IdComponent id,
         StatusModifierComponent modifier,
         StrengthComponent strength)
      : m_id {id},
        m_modifier {modifier},
        m_strength {strength} {}

  IdComponent id() const { return m_id; }

private:
  IdComponent m_id;

  StrengthComponent m_strength;
  StatusModifierComponent m_modifier;
};

} // namespace Rpg
