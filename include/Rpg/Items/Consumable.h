#pragma once

#include "Rpg/Components/StatusModifierComponent.h"
#include "Rpg/Components/IdComponent.h"
#include "Rpg/Components/StackComponent.h"

namespace Rpg
{

class Consumable
{
public:
  Consumable(IdComponent id,
             StackComponent stack,
             StatusModifierComponent modifier)
      : m_id {id},
        m_stack {stack},
        m_modifier {modifier} {}

  IdComponent id() const { return m_id; }

  bool operator==(const Consumable& comp) const
  {
    return m_id == comp.m_id;
  }

private:
  IdComponent m_id;

  StackComponent m_stack;
  StatusModifierComponent m_modifier;
};

} // namespace Rpg
