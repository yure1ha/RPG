#pragma once

#include <memory>
#include <string>

namespace Rpg::Effects
{

struct EffectAttributes
{
  enum class Type
  {
    buff,
    debuff,
  };

  int id {};
  int instanceId {};

  Type type {};
  std::string name {};
  std::string description {};

  int duration {};
  int currentStack {};
  int maxStack {};
};

class Effect
{
public:
  Effect() = default;
  explicit Effect(EffectAttributes Attr);

  [[nodiscard]] EffectAttributes getAttr() const { return attr_; };

private:
  EffectAttributes attr_ {};
};

using EffectSPtr = std::shared_ptr<Effect>;

} // namespace Rpg::Effects
