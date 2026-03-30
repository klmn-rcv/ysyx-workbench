#include <klib.h>

void test_strchr() {
	const char *s = "abca";

	assert(strchr(s, 'a') == s + 0);
	assert(strchr(s, 'b') == s + 1);
	assert(strchr(s, 'c') == s + 2);
	assert(strchr(s, 'x') == NULL);
	assert(strchr(s, '\0') == s + 4);
}

int main() {
	test_strchr();
	return 0;
}
