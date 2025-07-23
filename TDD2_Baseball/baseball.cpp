//#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strike;
	int ball;
};

class Baseball {
public:
	const int GAME_LENGTH = 3;
	explicit Baseball(const string& Num) : question{ Num } {}

	GuessResult guess(const string& guessNum) {
		assertIllegalArgument(guessNum);
		return playGame(guessNum);
	}

	const GuessResult& playGame(const std::string& guessNum) {
		GuessResult result = {};
		result.strike = countStrike(guessNum);
		result.ball = countBall(guessNum);
		result.solved = (result.strike == GAME_LENGTH);
		return result;
	}

	int countStrike(const std::string& guessNum) {
		int strike = 0;
		for (int i = 0; i < GAME_LENGTH; i++) {
			if (guessNum[i] == question[i]) strike++;
		}
		return strike;
	}

	int countBall(const std::string& guessNum) {
		int ball = 0;
		for (int i = 0; i < GAME_LENGTH; i++) {
			for (int j = 0; j < GAME_LENGTH; j++) {
				if (i == j) continue;
				if (guessNum[i] == question[j]) ball++;
			}
		}
		return ball;
	}

	void assertIllegalArgument(const std::string& guessNum) {
		if (guessNum.length() != GAME_LENGTH)
			throw length_error("Must be three letters.\n");

		for (char ch : guessNum) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.\n");
		}
		if (isDuplicatedNumber(guessNum))
			throw invalid_argument("Must not have the same number.\n");
	}

	bool isDuplicatedNumber(const std::string& guessNum) {
		return guessNum[0] == guessNum[1]
			|| guessNum[1] == guessNum[2]
			|| guessNum[2] == guessNum[0];
	}

private:
	string question;
};