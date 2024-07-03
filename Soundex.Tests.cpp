#include <gtest/gtest.h>
#include "Soundex.h"
class GenerateSoundexTest : public ::testing::Test {
protected:
    // Optionally, you can add setup code if needed
    void SetUp() override {}
 
    // Optionally, add teardown code if needed
    void TearDown() override {}
};

// Test cases for generateSoundex function
TEST(GenerateSoundexTest, EmptyName) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(GenerateSoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
    EXPECT_EQ(generateSoundex("C"), "C000");
    EXPECT_EQ(generateSoundex("D"), "D000");
    EXPECT_EQ(generateSoundex("E"), "E000");
}

TEST(GenerateSoundexTest, BasicNames) {
    EXPECT_EQ(generateSoundex("Ana"), "A500");
    EXPECT_EQ(generateSoundex("Bob"), "B100");
    EXPECT_EQ(generateSoundex("Carter"), "C636");
    EXPECT_EQ(generateSoundex("David"), "D130");
    EXPECT_EQ(generateSoundex("Eve"), "E100");
}

TEST(GenerateSoundexTest, NamesWithSpecialCharacters) {
    EXPECT_EQ(generateSoundex("O'Connor"), "O256");
    EXPECT_EQ(generateSoundex("McDonald"), "M235");
    EXPECT_EQ(generateSoundex("Van Gogh"), "V520");
}

TEST(GenerateSoundexTest, NameWithLowerCase) {
    EXPECT_EQ(generateSoundex("john"), "J500");
    EXPECT_EQ(generateSoundex("smith"), "S530");
    EXPECT_EQ(generateSoundex("emma"), "E500");
}

TEST(GenerateSoundexTest, NameWithNumbers) {
    EXPECT_EQ(generateSoundex("Taylor2"), "T460");
    EXPECT_EQ(generateSoundex("Parker123"), "P626");
}
