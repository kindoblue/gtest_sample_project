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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}

// https://www.safaribooksonline.com/library/view/modern-c-programming/9781941222423/f_0037.html