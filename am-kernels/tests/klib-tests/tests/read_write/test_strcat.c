#include <klib.h>

#define N 32

static char dst[N];
static char src[N];

static void fill_case(int dst_len, int src_len) {
	int i;
	for (i = 0; i < dst_len; i ++) {
		dst[i] = 'a' + (i % 26);
	}
	dst[dst_len] = '\0';

	for (i = 0; i < src_len; i ++) {
		src[i] = 'A' + (i % 26);
	}
	src[src_len] = '\0';

	for (i = dst_len + 1; i < N; i ++) {
		dst[i] = '*';
	}
}

void test_strcat() {
	int dst_len, src_len, i;
	for (dst_len = 0; dst_len <= 15; dst_len ++) {
		for (src_len = 0; src_len <= 15; src_len ++) {
			if (dst_len + src_len >= N - 1) continue;
			fill_case(dst_len, src_len);

			assert(strcat(dst, src) == dst);
			assert(strlen(dst) == (size_t)(dst_len + src_len));

			for (i = 0; i < dst_len; i ++) {
				assert(dst[i] == (char)('a' + (i % 26)));
			}
			for (i = 0; i < src_len; i ++) {
				assert(dst[dst_len + i] == src[i]);
			}
			assert(dst[dst_len + src_len] == '\0');
			for (i = dst_len + src_len + 1; i < N; i ++) {
				assert(dst[i] == '*');
			}
		}
	}
}

int main() {
	test_strcat();
	return 0;
}
