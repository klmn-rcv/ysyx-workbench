#include <klib.h>

#define N 32

static char src[N];
static char dst[N];

static void fill_src(int len) {
	int i;
	for (i = 0; i < len; i ++) {
		src[i] = 'a' + (i % 26);
	}
	src[len] = '\0';
}

static void fill_dst() {
	int i;
	for (i = 0; i < N; i ++) {
		dst[i] = '#';
	}
}

void test_strcpy() {
	int len, i;
	for (len = 0; len < N - 1; len ++) {
		fill_src(len);
		fill_dst();

		assert(strcpy(dst, src) == dst);
		assert(strlen(dst) == (size_t)len);

		for (i = 0; i <= len; i ++) {
			assert(dst[i] == src[i]);
		}
		for (i = len + 1; i < N; i ++) {
			assert(dst[i] == '#');
		}
	}
}

int main() {
	test_strcpy();
	return 0;
}
