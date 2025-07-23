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
	Baseball game{ "123" };
};

TEST_F(BaseballFixture, TryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCases) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strike);
	EXPECT_EQ(0, result.ball);
}

TEST_F(BaseballFixture, ReturnSolvedResult2Strikes0Ball) {
	GuessResult result = game.guess("125");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strike);
	EXPECT_EQ(0, result.ball);
}

TEST_F(BaseballFixture, ReturnSolvedResult1Strike2Balls) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strike);
	EXPECT_EQ(2, result.ball);
}
