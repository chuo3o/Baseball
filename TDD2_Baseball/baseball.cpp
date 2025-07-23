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
	}
};