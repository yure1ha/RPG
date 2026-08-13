#pragma once

#include "Rpg/Items/Item.h"

#include <memory>
#include <string>

namespace Rpg::Items
{

enum class ArmorType
{
  head,
  body,
  hands,
  legs,
};

struct ArmorStats
{
  ArmorType type {};

  int defense {};
};

class Armor : public Item
{
public:
  Armor(ItemAttributes attr, ArmorStats stats);

  [[nodiscard]] ArmorStats getStats() const { return stats; }

private:
  ArmorStats stats {};
};

using ArmorUPtr = std::unique_ptr<Armor>;

} // namespace Rpg::Items
