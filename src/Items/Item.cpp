#include "Rpg/Items/Item.h"

#include <algorithm>
#include <string>
#include <utility>

namespace Rpg::Items
{

Item::Item(ItemAttributes itemAttr) : attr_ {std::move(itemAttr)}
{
}

void Item::clampCount()
{
  attr_.currentQuantity = std::clamp(attr_.currentQuantity, 0, attr_.maxStack);
}

void Item::add(int count)
{
  if (count < 0) return;
  attr_.currentQuantity += count;
  clampCount();
}

void Item::remove(int count)
{
  if (count < 0) return;
  attr_.currentQuantity -= count;
  clampCount();
}

} // namespace Rpg::Items
