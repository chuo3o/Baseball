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
	explicit Baseball(const string& Num) : question{ Num } {}

	GuessResult guess(const string& guessNum) {
		assertIllegalArgument(guessNum);
		if(guessNum == question)
			return { true, 3, 0 };
		return { false, 0, 0 };
	}

	void assertIllegalArgument(const std::string& guessNum){
		if (guessNum.length() != 3)
			throw length_error("Must be three letters.\n");

		for (char ch : guessNum) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.\n");
		}
		if (isDuplicatedNumber(guessNum))
			throw invalid_argument("Must not have the same number.\n");
	}

	bool isDuplicatedNumber(const std::string& guessNum){
		return guessNum[0] == guessNum[1]
			|| guessNum[1] == guessNum[2]
			|| guessNum[2] == guessNum[0];
	}

private:
	string question;
};