#include "gmock/gmock.h"
#include "baseball_test.cpp"

using namespace testing;

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}