//
// Created by Stefano on 04/09/2017.
//

#ifndef SOUNDEX_SOUNDEX_H
#define SOUNDEX_SOUNDEX_H

#include <string>

class Soundex
{
public:
    std::string encode(const std::string& word) const {
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string& word) const {
        return word + "000";
    }
};

#endif //SOUNDEX_SOUNDEX_H