#include "Soundex.h"
#include <unordered_map>
#include <cctype>

// Function to get the Soundex code for a character
char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}

// Function to check if a Soundex code is valid to add
bool isValidCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

// Function to check if the length of the Soundex is valid
bool isSoundexLengthValid(const std::string& soundex) {
    return soundex.length() < 4;
}

// Function to add a Soundex code to the Soundex string and update previous code
void addSoundexCode(std::string& soundex, char code, char& prevCode) {
    if (isValidCode(code, prevCode) && isSoundexLengthValid(soundex)) {
        soundex.push_back(code);
        prevCode = code;
    }
}

// Function to update the Soundex string based on the name
std::string updateSoundex(const std::string& soundex, const std::string& name, char prevCode) {
    std::string newSoundex = soundex.substr(0, 1); // Initialize with the first character of soundex
    for (size_t i = 1; i < name.size() && newSoundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(newSoundex, code, prevCode);
    }
    newSoundex.append(4 - newSoundex.size(), '0'); // Pad with zeros to ensure length of 4
    return newSoundex;
}

// Function to generate Soundex code for a given name
std::string generateSoundex(const std::string& name) {
    if (name.empty()) {
        return "";
    }
    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(soundex[0]);
    return updateSoundex(soundex, name, prevCode);
}
