# 'Google_test' is the subproject name
project(Googletest)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(executeTests ../main_test.cpp ../../DnD_Editor/Feat.cpp ../../DnD_Editor/Capacity.cpp
        ../../DnD_Editor/Prerequisite.cpp ../../DnD_Editor/AbilityPrerequisite.cpp
        ../../DnD_Editor/Character.cpp ../../DnD_Editor/Skill.cpp ../../DnD_Editor/Bonus.cpp ../../DnD_Editor/BonusFeat.cpp
        ../../DnD_Editor/InheritanceExc.cpp ../../DnD_Editor/Proficiency.cpp ../../DnD_Editor/Feature.cpp
        ../../DnD_Editor/Race.cpp ../../DnD_Editor/Class.cpp ../../DnD_Editor/CharClass.cpp)
target_link_libraries(executeTests gtest gtest_main)