#include <gtest/gtest.h>
#include "Soundex.h"
class SoundexTest : public ::testing::Test {
protected:
    // Optionally, you can add setup code if needed
    void SetUp() override {}
 
    // Optionally, add teardown code if needed
    void TearDown() override {}
};
// Test cases for getSoundexCode function
TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(getSoundexCode('A'), '0');  // 'A' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('B'), '1');
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('D'), '3');
    EXPECT_EQ(getSoundexCode('E'), '0');  // 'E' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('F'), '1');
    EXPECT_EQ(getSoundexCode('G'), '2');
    EXPECT_EQ(getSoundexCode('H'), '0');  // 'H' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('I'), '0');  // 'I' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('J'), '2');
    EXPECT_EQ(getSoundexCode('K'), '2');
    EXPECT_EQ(getSoundexCode('L'), '4');
    EXPECT_EQ(getSoundexCode('M'), '5');
    EXPECT_EQ(getSoundexCode('N'), '5');
    EXPECT_EQ(getSoundexCode('O'), '0');  // 'O' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('P'), '1');
    EXPECT_EQ(getSoundexCode('Q'), '2');
    EXPECT_EQ(getSoundexCode('R'), '6');
    EXPECT_EQ(getSoundexCode('S'), '2');
    EXPECT_EQ(getSoundexCode('T'), '3');
    EXPECT_EQ(getSoundexCode('U'), '0');  // 'U' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('V'), '1');
    EXPECT_EQ(getSoundexCode('W'), '0');  // 'W' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('X'), '2');
    EXPECT_EQ(getSoundexCode('Y'), '0');  // 'Y' is not in the soundex map, should return '0'
    EXPECT_EQ(getSoundexCode('Z'), '2');
}

// Test cases for isValidCode function
TEST(SoundexTest, IsValidCode) {
    EXPECT_TRUE(isValidCode('1', '0'));
    EXPECT_TRUE(isValidCode('2', '1'));
    EXPECT_TRUE(isValidCode('3', '2'));
    EXPECT_TRUE(isValidCode('4', '3'));
    EXPECT_TRUE(isValidCode('5', '4'));
    EXPECT_TRUE(isValidCode('6', '5'));
    EXPECT_FALSE(isValidCode('0', '0'));  // '0' is not a valid code
    EXPECT_FALSE(isValidCode('2', '2'));  // '2' is already used as the previous code
    EXPECT_FALSE(isValidCode('3', '3'));  // '3' is already used as the previous code
}

// Test cases for isSoundexLengthValid function
TEST(SoundexTest, IsSoundexLengthValid) {
    EXPECT_TRUE(isSoundexLengthValid("A12"));
    EXPECT_TRUE(isSoundexLengthValid("A123"));
    EXPECT_FALSE(isSoundexLengthValid("A1234"));  // Length 4, should not be valid
}

// Test cases for addSoundexCode function
TEST(SoundexTest, AddSoundexCode) {
    std::string soundex = "A";
    char prevCode = '0';
    
    addSoundexCode(soundex, '1', prevCode);
    EXPECT_EQ(soundex, "A1");
    EXPECT_EQ(prevCode, '1');
    
    addSoundexCode(soundex, '2', prevCode);
    EXPECT_EQ(soundex, "A12");
    EXPECT_EQ(prevCode, '2');
    
    addSoundexCode(soundex, '0', prevCode);
    EXPECT_EQ(soundex, "A12");  // Should not add '0' as it's not a valid code
    EXPECT_EQ(prevCode, '2');
    
    // Test when soundex is already at max length 4
    soundex = "A123";
    addSoundexCode(soundex, '4', prevCode);
    EXPECT_EQ(soundex, "A123");
    EXPECT_EQ(prevCode, '3');
}

// Test cases for updateSoundex function
TEST(SoundexTest, UpdateSoundex) {
    std::string soundex = "A";
    char prevCode = '0';
    
    std::string updatedSoundex = updateSoundex(soundex, "Ana", prevCode);
    EXPECT_EQ(updatedSoundex, "A5");
    
    updatedSoundex = updateSoundex(soundex, "Alexander", prevCode);
    EXPECT_EQ(updatedSoundex, "A425");
    
    updatedSoundex = updateSoundex(soundex, "McDonald", prevCode);
    EXPECT_EQ(updatedSoundex, "M235");
}

// Test case for generateSoundex function
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("Ana"), "A5");
    EXPECT_EQ(generateSoundex("Alexander"), "A425");
    EXPECT_EQ(generateSoundex("McDonald"), "M235");
}

