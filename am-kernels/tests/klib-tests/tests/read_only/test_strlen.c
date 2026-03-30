#include <klib.h>

void test_strlen() {
	assert(strlen("") == 0);
	assert(strlen("a") == 1);
	assert(strlen("abc") == 3);
	assert(strlen("hello, world") == 12);

	char s[] = {'x', 'y', 'z', '\0', 'q'};
	assert(strlen(s) == 3);
}

int main() {
	test_strlen();
	return 0;
}
