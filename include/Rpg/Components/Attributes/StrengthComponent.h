#pragma once

#include <cassert>
#include <cstdint>

namespace Rpg
{

class StrengthComponent
{
public:
  StrengthComponent(std::int32_t effective = kMinStrength, std::int32_t base = kMinStrength)
      : m_effective {effective}, m_base {base}
  {
    assert(isValid());
  }

  static constexpr std::int32_t kMinStrength {1};
  static constexpr std::int32_t kMaxStrength {99};

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
    return m_effective >= kMinStrength
        && m_effective <= kMaxStrength
        && m_base      >= kMinStrength
        && m_base      <= kMaxStrength;
  }
};

} // namespace Rpg
