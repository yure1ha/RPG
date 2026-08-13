#include "Rpg/Effects/Effect.h"

#include <utility>

namespace Rpg::Effects
{

Effect::Effect(EffectAttributes Attr) : attr_ {std::move(Attr)}
{
}

} // namespace Rpg::Effects
