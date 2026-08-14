cmake_minimum_required(VERSION 4.2)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

add_library(Rpg include/Rpg/Components/IdComponent.h
        include/Rpg/Components/Attributes/HealthComponent.h
        src/Components/HealthComponent.cpp
        include/Rpg/Components/Attributes/DefenseComponent.h
        include/Rpg/Components/Attributes/StrengthComponent.h
        include/Rpg/Components/StackComponent.h
        include/Rpg/Components/ContainerComponent.h
        include/Rpg/Components/StatusModifierComponent.h
        include/Rpg/Components/ActiveModifiersComponent.h
        include/Rpg/Entities/Character.h
        include/Rpg/Items/Consumable.h
        include/Rpg/Items/Weapon.h
        include/Rpg/Items/Armor.h)

target_include_directories(Rpg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(RPG main.cpp)

target_link_libraries(RPG PRIVATE Rpg)
