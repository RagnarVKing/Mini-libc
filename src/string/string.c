// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while(source[i]) {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	for(int i = 0; i < (int)len; i++) {
		destination[i] = source[i];
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0;
	while(destination[i]) {
		i++;
	}
	int j = 0;
	while(source[j]) {
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = 0;
	while(destination[i]) {
		i++;
	}
	for(int j = 0; j < (int)len; j++, i++) {
		destination[i] = source[j];
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while(*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
		while(len && *str1 && (*str1 == *str2)) {
		str1++;
		str2++;
		len--;
	}
	if(len == 0) {
		return 0;
	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	while(str[i]) {
		if(str[i] == c)
		{
			return (char *)(str + i);
		}
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int len = strlen(str);
	for(int i = len - 1; i >= 0; i--) {
		if(str[i] == c) {
			return (char *)(str + i);
		}
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int len = strlen(needle);
	while(*haystack) {
		if(strncmp(haystack, needle, len) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int len = strlen(needle);
	int lenn = strlen(haystack);
	haystack += lenn;
	while(lenn) {
		if(strncmp(haystack, needle, len) == 0) {
			return (char *)haystack;
		}
		lenn--;
		haystack--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	strncpy(destination, source, num);

	return (char *)destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *)destination;
	if((d < (char *)source) || (d >= ((char *)source + num))) {
		while(num) {
			*d = *(char *)source;
			d++;
			source++;
			num--;
		}
	} else {
		d += num;
		source += num;
		while(num) {
			d--;
			source--;
			*d = *(char *)source;
			num--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	int n = strncmp(ptr1, ptr2, num);
	return n;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *s = (char *)source;
	while(num) {
		*s = (char)value;
		s++;
		num--;
	}
	return source;
}
