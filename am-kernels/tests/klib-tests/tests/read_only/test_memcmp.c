#include <klib.h>

static int sgn(int x) {
	return (x > 0) - (x < 0);
}

void test_memcmp() {
	uint8_t a[] = {1, 2, 3, 4, 5};
	uint8_t b[] = {1, 2, 3, 4, 5};
	uint8_t c[] = {1, 2, 9, 4, 5};

	assert(memcmp(a, b, 0) == 0);
	assert(memcmp(a, b, 5) == 0);

	assert(sgn(memcmp(a, c, 2)) == 0);
	assert(sgn(memcmp(a, c, 3)) < 0);
	assert(sgn(memcmp(c, a, 3)) > 0);
}

int main() {
	test_memcmp();
	return 0;
}
