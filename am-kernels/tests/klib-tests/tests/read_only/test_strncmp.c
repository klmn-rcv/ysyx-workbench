#include <klib.h>

static int sgn(int x) {
	return (x > 0) - (x < 0);
}

void test_strncmp() {
	assert(strncmp("abc", "xyz", 0) == 0);
	assert(strncmp("abc", "abc", 3) == 0);
	assert(strncmp("abcd", "abce", 3) == 0);

	assert(sgn(strncmp("abcd", "abce", 4)) < 0);
	assert(sgn(strncmp("abce", "abcd", 4)) > 0);

	assert(sgn(strncmp("abc", "ab", 3)) > 0);
	assert(sgn(strncmp("ab", "abc", 3)) < 0);
}

int main() {
	test_strncmp();
	return 0;
}
