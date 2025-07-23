#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

class BaseballFixture : public Test {
public:
	void assertIllegalArgument(string guessNum) {
		// game.guess() 수행 후 exception 이 발생해야 pass
		try {
			game.guess(guessNum);
			FAIL();
		}
		catch (exception e) {
			cout << e.what();
		}
	}
	Baseball game;
};

TEST_F(BaseballFixture, TryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCases) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

