#include <klib.h>

static int sgn(int x) {
	return (x > 0) - (x < 0);
}

void test_strcmp() {
	assert(strcmp("", "") == 0);
	assert(strcmp("abc", "abc") == 0);

	assert(sgn(strcmp("abc", "abd")) < 0);
	assert(sgn(strcmp("abd", "abc")) > 0);

	assert(sgn(strcmp("abc", "ab")) > 0);
	assert(sgn(strcmp("ab", "abc")) < 0);

	assert(sgn(strcmp("A", "a")) < 0);
}

int main() {
	test_strcmp();
	return 0;
}
