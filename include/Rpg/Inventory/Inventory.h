#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace Rpg::Inventory
{

template <typename T>
class Inventory
{
public:
  using ItemUPtr = std::unique_ptr<T>;
  using Container = std::vector<ItemUPtr>;

  [[nodiscard]] Container getInventory() const { return inventory_; }

  template <typename Compare>
  void sort(Compare comp) { std::ranges::stable_sort(inventory_, comp); }

  T* search(int instanceId) const
  {
    for (const ItemUPtr& item : inventory_)
    {
      if (item->getStats().instanceId == instanceId) { return item.get(); }
    }
    return nullptr;
  }

  void add(ItemUPtr item)
  {
    if (!item) return;
    inventory_.push_back(std::move(item));
  }

  ItemUPtr remove(int instanceId)
  {
    const auto it {
        std::ranges::find_if(inventory_, [instanceId](const auto& a)
                             { return a->getAttr().instanceId == instanceId; })};

    if (it == inventory_.end()) return nullptr;

    ItemUPtr removed {std::move(*it)};
    inventory_.erase(it);

    return removed;
  }

private:
  Container inventory_ {};
};

} // namespace Rpg::Inventory
