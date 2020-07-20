#include "../DnD_Editor/Skill.h"
#include "../DnD_Editor/AbilityPrerequisite.h"
#include "../DnD_Editor/BonusFeat.h"
#include "../DnD_Editor/InheritanceExc.h"
#include "../DnD_Editor/Feature.h"
#include <gtest/gtest.h>

//SKILL_TESTS
TEST(SkillTests, EqualityTest) //EQUALITY
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n1", Head::ability::dexterity, 0, "d1", 0);
    ASSERT_EQ(s1 == s2, 1);
}
TEST(SkillTests, InequalityTest1) //INEQUALITY BY NAME
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n2", Head::ability::dexterity, 0, "d1", 0);
    ASSERT_EQ(s1 != s2, 1);
}
TEST(SkillTests, InequalityTest2) //INEQUALITY BY ABILITY
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n1", Head::ability::strength, 0, "d1", 0);
    ASSERT_EQ(s1 != s2, 1);
}
TEST(SkillTests, InequalityTest3) //INEQUALITY BY NAME ARMOR PENALTY
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n1", Head::ability::dexterity, 1, "d1", 0);
    ASSERT_EQ(s1 != s2, 1);
}
TEST(SkillTests, InequalityTest4) //INEQUALITY BY DESCRIPTION
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n1", Head::ability::dexterity, 0, "d2", 0);
    ASSERT_EQ(s1 != s2, 1);
}
TEST(SkillTests, InequalityTest5) //INEQUALITY BY TRAINING
{
    Skill s1("n1", Head::ability::dexterity, 0, "d1", 0);
    Skill s2("n1", Head::ability::dexterity, 0, "d1", 1);
    ASSERT_EQ(s1 != s2, 1);
}

//ABILITY_PREREQUISITE_TESTS
TEST(AbilityPrerequisiteTests, EqualityTest) //EQUALITY
{
    Prerequisite* ptr = new AbilityPrerequisite(10, Head::ability::strength, "d1");
    Prerequisite* ptr2 = new AbilityPrerequisite(10, Head::ability::strength, "d1");
    ASSERT_EQ(dynamic_cast<AbilityPrerequisite *>(ptr)->operator==(ptr2), 1);

}
TEST(AbilityPrerequisiteTests, InequalityTest1) //INEQUALITY BY VALUE
{
    Prerequisite* ptr = new AbilityPrerequisite(12, Head::ability::strength, "d1");
    Prerequisite* ptr2 = new AbilityPrerequisite(11, Head::ability::strength, "d1");
    ASSERT_EQ(dynamic_cast<AbilityPrerequisite *>(ptr)->operator==(ptr2), 0);


}
TEST(AbilityPrerequisiteTests, InequalityTest2) //INEQUALITY BY ABILITY
{
    Prerequisite* ptr = new AbilityPrerequisite(12, Head::ability::strength, "d1");
    Prerequisite* ptr2 = new AbilityPrerequisite(12, Head::ability::charisma, "d1");
    ASSERT_EQ(dynamic_cast<AbilityPrerequisite *>(ptr)->operator==(ptr2), 0);

}
TEST(AbilityPrerequisiteTests, InequalityTest3) //INEQUALITY BY DESCRIPTION
{
    Prerequisite* ptr = new AbilityPrerequisite(12, Head::ability::strength, "d1");
    Prerequisite* ptr2 = new AbilityPrerequisite(12, Head::ability::strength, "d2");
    ASSERT_EQ(dynamic_cast<AbilityPrerequisite *>(ptr)->operator==(ptr2), 0);

}
TEST(AbilityPrerequisiteTests, VerifyTest) //VERIFY_TEST
{

    Character c;
    AbilityScore a[ABILITIES];
    a[0].ability = Head::ability::strength;
    a[0].score = 18;
    c.setAbilityScore(a);
    Prerequisite* ptr = new AbilityPrerequisite(12, Head::ability::strength, "d1");
    ASSERT_EQ(ptr->verify(&c), 1);
}

//BONUS_TESTS
TEST(BonusTests, EqualityTest) //EQUALITY
{
    Bonus b1("t1", 10);
    Bonus b2("t1", 10);
    ASSERT_EQ(b1 == b2, 1);
}
TEST(BonusTests, InequalityTest1) //INEQUALITY BY TYPE
{
    Bonus b1("t1", 10);
    Bonus b2("t2", 10);
    ASSERT_EQ(b1 == b2, 0);
}
TEST(BonusTests, InequalityTest2) //INEQUALITY BY VALUE
{
    Bonus b1("t1", 10);
    Bonus b2("t1", 22);
    ASSERT_EQ(b1 == b2, 0);
}

//CAPACITY_TESTS
TEST(CapacityTests, EqualityTest) //EQUALITY
{
    Capacity* ptr = new Capacity("n1", "d1");
    Capacity* ptr2 = new Capacity("n1", "d1");
    ASSERT_EQ(ptr->operator==(ptr2), 1);
}
TEST(CapacityTests, InequalityTest1) //INEQUALITY BY NAME
{
    Capacity* ptr = new Capacity("n1", "d1");
    Capacity* ptr2 = new Capacity("n2", "d1");
    ASSERT_EQ(ptr->operator!=(ptr2), 1);
}
TEST(CapacityTests, InequalityTest2) //INEQUALITY BY DESCRIPTION
{
    Capacity* ptr = new Capacity("n1", "d1");
    Capacity* ptr2 = new Capacity("n1", "d2");
    ASSERT_EQ(ptr->operator!=(ptr2), 1);
}
TEST(CapacityTests, InheritanceTest) //INHERITANCE EXCEPTION
{
    Capacity* ptr = new Capacity("n1", "d1");
    Capacity* ptr2 = new Feat("n1", "d1");
    try {
        bool test = ptr->operator==(ptr2);
        ASSERT_EQ(1, 2);
    }
    catch(InheritanceExc &e){
        ASSERT_EQ(e.what(), "Cannot compare capacities instances and non-capacities ones.");
    }
}

//PROFICIENCY_TESTS
TEST(ProficiencyTests, EqualityTest) //EQUALITY
{
    Proficiency p1("t1", "s1");
    Proficiency p2("t1", "s1");
    ASSERT_EQ(p1 == p2, 1);
}
TEST(ProficiencyTests, InequalityTest1) //INEQUALITY BY TYPE
{
    Proficiency p1("t1", "s1");
    Proficiency p2("t2", "s1");
    ASSERT_EQ(p1 != p2, 1);
}
TEST(ProficiencyTests, InequalityTest2) //INEQUALITY BY SPECS
{
    Proficiency p1("t1", "s1");
    Proficiency p2("t1", "s2");
    ASSERT_EQ(p1 != p2, 1);
}

//FEATURE_TESTS
TEST(FeatureTests, EqualityTest) //EQUALITY
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Feature("n1", "d1");
    Bonus b("t1", 10);
    dynamic_cast<Feature*>(ptr)->addBonus(b);
    dynamic_cast<Feature*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<Feature*>(ptr)->operator==(ptr2), 1);
}
TEST(FeatureTests, InequalityTest1) //INEQUALITY BY NAME
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Feature("n2", "d1");
    Bonus b("t1", 10);
    dynamic_cast<Feature*>(ptr)->addBonus(b);
    dynamic_cast<Feature*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<Feature*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatureTests, InequalityTest2) //INEQUALITY BY DESCRIPTION
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Feature("n1", "d2");
    Bonus b("t1", 10);
    dynamic_cast<Feature*>(ptr)->addBonus(b);
    dynamic_cast<Feature*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<Feature*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatureTests, InequalityTest3) //INEQUALITY BY BONUSES CONTENT
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Feature("n2", "d1");
    Bonus b("t1", 10);
    Bonus b2("t1", 11);
    dynamic_cast<Feature*>(ptr)->addBonus(b);
    dynamic_cast<Feature*>(ptr2)->addBonus(b2);
    ASSERT_EQ(dynamic_cast<Feature*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatureTests, InequalityTest4) //INEQUALITY BY BONUSES LENGTH
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Feature("n2", "d1");
    Bonus b("t1", 10);
    Bonus b2("t1", 11);
    dynamic_cast<Feature*>(ptr)->addBonus(b);
    dynamic_cast<Feature*>(ptr)->addBonus(b2);
    dynamic_cast<Feature*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<Feature*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatureTests, InheritanceTest) //INHERITANCE
{
    Capacity* ptr = new Feature("n1", "d1");
    Capacity* ptr2 = new Capacity("n2", "d1");
    try{
        dynamic_cast<Feature*>(ptr)->operator==(ptr2);
    }
    catch(InheritanceExc e){
        ASSERT_EQ(e.what(), "Cannot compare features instances with non-feature ones.");
    }
}

//FEAT_TESTS
TEST(FeatTests, EqualityTest) //EQUALITY
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feat("n1", "d1");
    AbilityPrerequisite a(10, Head::ability::strength, "d1");
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a);
    dynamic_cast<Feat*>(ptr2)->addPrerequisite(&a);
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->operator==(ptr2), 1);
}
TEST(FeatTests, InequalityTest1) //INEQUALITY BY NAME
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feat("n2", "d1");
    AbilityPrerequisite a(10, Head::ability::strength, "d1");
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a);
    dynamic_cast<Feat*>(ptr2)->addPrerequisite(&a);
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatTests, InequalityTest2) //INEQUALITY BY DESCRIPTION
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feat("n1", "d2");
    AbilityPrerequisite a(10, Head::ability::strength, "d1");
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a);
    dynamic_cast<Feat*>(ptr2)->addPrerequisite(&a);
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatTests, InequalityTest3) //INEQUALITY BY PREREQUISITES CONTENT
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feat("n1", "d2");
    AbilityPrerequisite a(10, Head::ability::strength, "d1");
    AbilityPrerequisite a2(22, Head::ability::strength, "d1");
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a);
    dynamic_cast<Feat*>(ptr2)->addPrerequisite(&a2);
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatTests, InequalityTest4) //INEQUALITY BY PREREQUISITES LENGTH
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feat("n1", "d2");
    AbilityPrerequisite a(10, Head::ability::strength, "d1");
    AbilityPrerequisite a2(22, Head::ability::strength, "d1");
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a);
    dynamic_cast<Feat*>(ptr)->addPrerequisite(&a2);
    dynamic_cast<Feat*>(ptr2)->addPrerequisite(&a2);
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->operator!=(ptr2), 1);
}
TEST(FeatTests, InheritanceTest) //INHERITANCE TEST
{
    Capacity* ptr = new Feat("n1", "d1");
    Capacity* ptr2 = new Feature("n1", "d2");
    try{
        dynamic_cast<Feat*>(ptr)->operator==(ptr2);
    }
    catch(InheritanceExc &e){
        ASSERT_EQ(e.what(), "Cannot compare feat instances with non-feat ones.");
    }
}
TEST(FeatTests, PrerequisiteAdditionTest) //PREREQUISITE ADDITION TEST
{
    Capacity* ptr = new Feat("n1", "d1");
    AbilityPrerequisite a(10, Head::ability::strength, "d"); //The first time you add a prerequisite
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->addPrerequisite(&a), 1); //you will have success and test will evaluate to true.
    ASSERT_EQ(dynamic_cast<Feat*>(ptr)->addPrerequisite(&a), 0);      //The second time you try to add the same prerequisite
                                                                      //you will fail and test will evaluate to false.
}

//BONUS_FEAT_TESTS
TEST(BonusFeatTests, EqualityTest) //EQUALITY
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 0, "b1", "d1");
    Bonus b("t1", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator==(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest1) //INEQUALITY BY STACKABLE
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(1, 0, "b1", "d1");
    Bonus b("t1", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest2) //INEQUALITY BY CHOICE
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 1, "b1", "d1");
    Bonus b("t1", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest3) //INEQUALITY BY NAME
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 0, "b2", "d1");
    Bonus b("t1", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest4) //INEQUALITY BY DESCRIPTION
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 0, "b1", "d2");
    Bonus b("t1", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest5) //INEQUALITY BY BONUSES CONTENT
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 0, "b1", "d1");
    Bonus b("t1", 10);
    Bonus b2("t1", 11);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b2);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}
TEST(BonusFeatTests, InequalityTest6) //INEQUALITY BY BONUSES LENGTH
{
    Capacity* ptr = new BonusFeat(0, 0, "b1", "d1");
    Capacity* ptr2 = new BonusFeat(0, 0, "b1", "d1");
    Bonus b("t1", 10);
    Bonus b2("t2", 10);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b);
    dynamic_cast<BonusFeat*>(ptr)->addBonus(b2);
    dynamic_cast<BonusFeat*>(ptr2)->addBonus(b);
    ASSERT_EQ(dynamic_cast<BonusFeat*>(ptr)->operator!=(ptr2), 1);
}

//RACE_TESTS
TEST(RaceTests, AutoLangAddition) //AUTOMATIC_LANGUAGES_ADDITION
{
    Race r;
    ASSERT_EQ(r.addAutoLang("Common"), 1);
    ASSERT_EQ(r.addAutoLang("Common"), 0);
}
TEST(RaceTests, BonusLangAddition) //BONUS_LANGUAGES_ADDITION
{
    Race r;
    ASSERT_EQ(r.addBonusLang("Common"), 1);
    ASSERT_EQ(r.addBonusLang("Common"), 0);
}
TEST(RaceTests, RacialTraitAddition) //RACIAL_TRAIT_ADDITION
{
    Race r;
    ASSERT_EQ(r.addTrait(new Capacity("n1", "d1")), 1);
    ASSERT_EQ(r.addTrait(new Capacity("n1", "d1")), 0);
}

//CLASS_TESTS
TEST(ClassTests, PrerequisiteAdditionTest) //PREREQUISITE_ADDITION_TEST
{
    Class c;
    AbilityPrerequisite a(10, Head::ability::strength, "d"); //The first time you add a prerequisite you will have success
    ASSERT_EQ(c.addPrerequisite(&a), 1);                    //and test will evaluate to true.
    ASSERT_EQ(c.addPrerequisite(&a), 0);                             //The second time you try to add the same prerequisite
                                                                     //you will fail and test will evaluate to false.

}
TEST(ClassTests, PrerequisiteVerificationTest) //PREREQUISITE_VERIFICATION_TEST
{
    Class c;
    Character Char;
    AbilityScore a[ABILITIES];
    a[0].ability = Head::ability::strength;
    a[0].score = 18;
    Char.setAbilityScore(a);
    Prerequisite* ptr = new AbilityPrerequisite(12, Head::ability::strength, "d1");
    c.addPrerequisite(ptr);
    ASSERT_EQ(c.checkPrerequisites(&Char), 1);

}
TEST(ClassTests, ProficiencyAdditionTest) //PROFICIENCY_ADDITION_TEST
{
    Class c;
    Proficiency p("t1", "s1");
    Proficiency p2("t1", "s2");
    Proficiency p3("t1", "ANY");
    ASSERT_EQ(c.addProficiency(p), 1);
    ASSERT_EQ(c.addProficiency(p), 0);
    ASSERT_EQ(c.addProficiency(p2), 1);
    ASSERT_EQ(c.getProficiencies().size(), 2);
    ASSERT_EQ(c.addProficiency(p3), 1);
    ASSERT_EQ(c.getProficiencies().size(), 1);
}
TEST(ClassTests, SkillAdditionTest) //SKILL_ADDITION_TEST
{
    Skill s("n", Head::ability::strength, 1, "d", 1);
    Class c;
    ASSERT_EQ(c.addSkill(s), 1);
    ASSERT_EQ(c.addSkill(s), 0);
}
TEST(ClassTests, FeatureAdditionTest) //FEATURE_ADDITION_TEST
{
    Capacity* ptr = new Capacity("n1", "d1");
    Class c;
    ASSERT_EQ(c.addCapacity(1, ptr), 1);
    ASSERT_EQ(c.addCapacity(1, ptr), 0);
}

int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
