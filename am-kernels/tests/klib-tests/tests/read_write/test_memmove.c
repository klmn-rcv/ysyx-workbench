#include <klib.h>

#define N 32

static uint8_t data[N];
static uint8_t expect[N];
static uint8_t tmp[N];

static int min_int(int a, int b) {
	return a < b ? a : b;
}

static void reset() {
	int i;
	for (i = 0; i < N; i ++) {
		data[i] = i + 1;
		expect[i] = data[i];
	}
}

static void ref_memmove(uint8_t *dst, const uint8_t *src, int n) {
	int i;
	for (i = 0; i < n; i ++) {
		tmp[i] = src[i];
	}
	for (i = 0; i < n; i ++) {
		dst[i] = tmp[i];
	}
}

static void check_all() {
	int i;
	for (i = 0; i < N; i ++) {
		assert(data[i] == expect[i]);
	}
}

void test_memmove() {
	int src_off, dst_off, n;
	for (src_off = 0; src_off < N; src_off ++) {
		for (dst_off = 0; dst_off < N; dst_off ++) {
			int max_n = min_int(N - src_off, N - dst_off);
			for (n = 0; n <= max_n; n ++) {
				reset();
				ref_memmove(expect + dst_off, expect + src_off, n);
				assert(memmove(data + dst_off, data + src_off, n) == data + dst_off);
				check_all();
			}
		}
	}
}

int main() {
	test_memmove();
	return 0;
}
