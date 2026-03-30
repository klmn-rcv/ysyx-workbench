#include <klib.h>

void test_strrchr() {
	const char *s = "abca";

	assert(strrchr(s, 'a') == s + 3);
	assert(strrchr(s, 'b') == s + 1);
	assert(strrchr(s, 'c') == s + 2);
	assert(strrchr(s, 'x') == NULL);
	assert(strrchr(s, '\0') == s + 4);
}

int main() {
	test_strrchr();
	return 0;
}
