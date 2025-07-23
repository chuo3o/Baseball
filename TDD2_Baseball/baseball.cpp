//#include <string>
#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNum) {
		if (guessNum.length() != 3)
			throw length_error("Must be three letters.\n");

		for (char ch : guessNum) {
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must be number.\n");
		}
		if(guessNum[0] == guessNum[1] 
			|| guessNum[1] == guessNum[2]
			|| guessNum[2] == guessNum[0])
			throw invalid_argument("Must not have the same number.\n");
	}
};