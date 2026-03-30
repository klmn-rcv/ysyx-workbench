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
		dst[i] = '@';
	}
}

void test_strncpy() {
	int src_len, n, i;
	for (src_len = 0; src_len <= 20; src_len ++) {
		fill_src(src_len);
		for (n = 0; n <= 20; n ++) {
			fill_dst();

			assert(strncpy(dst, src, n) == dst);

			for (i = 0; i < n; i ++) {
				if (i < src_len) {
					assert(dst[i] == src[i]);
				} else {
					assert(dst[i] == '\0');
				}
			}
			for (i = n; i < N; i ++) {
				assert(dst[i] == '@');
			}
		}
	}
}

int main() {
	test_strncpy();
	return 0;
}
