#include <klib.h>

#define N 32

static uint8_t src[N];
static uint8_t dst[N];

static void reset() {
	int i;
	for (i = 0; i < N; i ++) {
		src[i] = i + 1;
		dst[i] = 0xcc;
	}
}

static void check_eq(int l, int r, uint8_t val) {
	int i;
	for (i = l; i < r; i ++) {
		assert(dst[i] == val);
	}
}

static void check_copy(int l, int r) {
	int i;
	for (i = l; i < r; i ++) {
		assert(dst[i] == src[i]);
	}
}

void test_memcpy() {
	int l, r;

	reset();
	assert(memcpy(dst, src, 0) == dst);
	check_eq(0, N, 0xcc);

	for (l = 0; l < N; l ++) {
		for (r = l + 1; r <= N; r ++) {
			reset();
			assert(memcpy(dst + l, src + l, r - l) == dst + l);
			check_eq(0, l, 0xcc);
			check_copy(l, r);
			check_eq(r, N, 0xcc);
		}
	}
}

int main() {
	test_memcpy();
	return 0;
}
