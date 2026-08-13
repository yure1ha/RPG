#pragma once

#include <cassert>
#include <cstdint>

namespace Rpg
{

class DefenseComponent
{
public:
  DefenseComponent(std::int32_t effective = kMinDefense, std::int32_t base = kMinDefense)
      : m_effective {effective}, m_base {base}
  {
    assert(isValid());
  };

  static constexpr std::int32_t kMinDefense {1};
  static constexpr std::int32_t kMaxDefense {99};

  std::int32_t effective() const { return m_effective; }
  std::int32_t base() const { return m_base; }

  void increase(std::int32_t amount)
  {
    m_effective += amount;
    assert(isValid());
  }

  void decrease(std::int32_t amount)
  {
    m_effective -= amount;
    assert(isValid());
  }

  void reset()
  {
    m_effective = m_base;
    assert(isValid());
  }

private:
  std::int32_t m_effective {};
  std::int32_t m_base {};

  bool isValid() const
  {
    return m_effective >= kMinDefense
        && m_effective <= kMaxDefense
        && m_base      >= kMinDefense
        && m_base      <= kMaxDefense;
  }
};

} // namespace Rpg
