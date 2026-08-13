#pragma once

#include "Rpg/Components/IdComponent.h"

#include <algorithm>
#include <optional>
#include <vector>

namespace Rpg
{

template <typename T>
class ContainerComponent
{
public:
  void add(const T& item)
  {
    m_items.push_back(item);
  }

  void remove(const T& item)
  {
    std::erase(m_items, item);
  }

  std::optional<IdComponent> get(const T& item)
  {
    auto it {std::ranges::find(m_items, item)};

    if (it != m_items.end()) return it->id();

    return std::nullopt;
  }

private:
  std::vector<T> m_items {};
};

} // namespace Rpg
