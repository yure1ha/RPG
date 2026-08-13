#pragma once

#include "Rpg/Components/StatusModifierComponent.h"

#include <vector>

namespace Rpg
{

class ActiveModifiersComponent
{
public:
  void add(const StatusModifierComponent& modifier)
  {
    m_modifiers.push_back(modifier);
  }

  void remove(const StatusModifierComponent& modifier)
  {
    std::erase(m_modifiers, modifier);
  }

private:
  std::vector<StatusModifierComponent> m_modifiers {};
};

} // namespace Rpg
