#include <gmock/gmock.h>
#include "../src/soundex.h"

using ::testing::Eq;

// fixture class
class SoundexEncoding : public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {

    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {

    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}
