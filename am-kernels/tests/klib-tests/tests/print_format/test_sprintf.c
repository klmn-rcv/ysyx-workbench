#include <limits.h>
#include <klib.h>

void test_sprintf_d() {
	int data[] = {
		0,
		INT_MAX / 17,
		INT_MAX,
		INT_MIN,
		INT_MIN + 1,
		(int)(UINT_MAX / 17),
		INT_MAX / 17,
		(int)UINT_MAX,
	};

	const char *expect[] = {
		"0",
		"126322567",
		"2147483647",
		"-2147483648",
		"-2147483647",
		"252645135",
		"126322567",
		"-1",
	};

	char buf[128];
	int n = sizeof(data) / sizeof(data[0]);
	int i;
	for (i = 0; i < n; i ++) {
		int ret = sprintf(buf, "%d", data[i]);
		assert(strcmp(buf, expect[i]) == 0);
		assert(ret == (int)strlen(expect[i]));
	}
}

void test_sprintf_x() {
	int data[] = {
		0,
		0x12,
		INT_MAX,
		INT_MIN,
		(int)UINT_MAX,
	};

	const char *expect[] = {
		"0",
		"12",
		"7fffffff",
		"80000000",
		"ffffffff",
	};

	char buf[128];
	int n = sizeof(data) / sizeof(data[0]);
	int i;
	for (i = 0; i < n; i ++) {
		int ret = sprintf(buf, "%x", data[i]);
		assert(strcmp(buf, expect[i]) == 0);
		assert(ret == (int)strlen(expect[i]));
	}
}

void test_sprintf_u() {
	int data[] = {
		0,
		1,
		INT_MAX,
		INT_MIN,
		(int)UINT_MAX,
	};

	const char *expect[] = {
		"0",
		"1",
		"2147483647",
		"2147483648",
		"4294967295",
	};

	char buf[128];
	int n = sizeof(data) / sizeof(data[0]);
	int i;
	for (i = 0; i < n; i ++) {
		int ret = sprintf(buf, "%u", data[i]);
		assert(strcmp(buf, expect[i]) == 0);
		assert(ret == (int)strlen(expect[i]));
	}
}

void test_sprintf_mix() {
	char buf[128];
	int ret = sprintf(buf, "A:%d B:%s C:%d", -42, "xyz", 7);
	assert(strcmp(buf, "A:-42 B:xyz C:7") == 0);
	assert(ret == (int)strlen("A:-42 B:xyz C:7"));

	ret = sprintf(buf, "%s:%d", "num", 0);
	assert(strcmp(buf, "num:0") == 0);
	assert(ret == (int)strlen("num:0"));

	ret = sprintf(buf, "H:%x U:%u", 0x2a, (int)UINT_MAX);
	assert(strcmp(buf, "H:2a U:4294967295") == 0);
	assert(ret == (int)strlen("H:2a U:4294967295"));
}

int main() {
	test_sprintf_d();
	test_sprintf_x();
	test_sprintf_u();
	test_sprintf_mix();
	return 0;
}
