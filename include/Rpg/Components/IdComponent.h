#pragma once

#include <cstdint>

namespace Rpg
{

struct IdComponent
{
  std::int32_t id {};

  bool operator==(const IdComponent& comp) const { return id == comp.id; }
};

} // namespace Rpg
