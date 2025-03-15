// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while ((*destination++ = * source++) != '\0');
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;
	for (i = 0; i < len && source[i] != '\0'; i++){
		destination[i] = source[i];
	}
	for (; i < len; i++){
		destination[i] = '\0';
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *dest_end = destination + strlen(destination);
	while ((*dest_end++ = *source++) != '\0');
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *dest_end = destination + strlen(destination);
	size_t i;
	for (i = 0; i < len && source[i] != '\0'; i++){
		dest_end[i] = source[i];
	}
	dest_end[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 && (*str1 == *str2)){
		str1++;
		str2++;
	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i;
	for (i = 0; i < len && str1[i] && (str1[i] == str2[i]); i++);
	return (i == len) ? 0 : (unsigned char)str1[i] - (unsigned char)str2[i];
	return -1;
}

size_t strlen(const char *str)
{
	const char *s = str;
	while (*s)
		s++;
	return s - str;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0') {
		if (*str == (char)c)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *last = NULL;
	while (*str != '\0'){
		if (*str == (char)c)
			last = str;
		str++;
	}
	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0'){
		return (char *)haystack;
	}
	while (*haystack){
		const char *h = haystack;
		const char *n = needle;
		while (*h && *n && *h == *n){
			h++;
			n++;
		}
		if (*n == '\0'){
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *result = NULL;
	if (*needle == '\0'){
		return (char *)haystack;
	}
	while (*haystack){
		const char *h = haystack;
		const char *n = needle;
		while (*h && *n && *h == *n){
			h++;
			n++;
		}
		if (*n == '\0'){
			result = (char *)haystack;
		}		
		haystack++;
	}
	return result;
}

void *memcpy(void *destination, const void *source, size_t n)
{
	/* TODO: Implement memcpy(). */
	unsigned char *dest = destination;
	const unsigned char *src = source;
	for (size_t i = 0; i < n; i++){
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t n)
{
	/* TODO: Implement memmove(). */
	unsigned char *dest = destination;
	const unsigned char *src = source;
	if (dest < src){
		for (size_t i = 0; i < n; i++){
			dest[i] = src[i];
		}
	} else {
		for (size_t i = n; i != 0; i--){
			dest[i - 1] = src[i - 1];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = ptr1;
	const unsigned char *p2 = ptr2;
	for (size_t i = 0; i < n; i++){
		if (p1[i] != p2[i]){
			return p1[i] - p2[i];
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t n)
{
	/* TODO: Implement memset(). */
	unsigned char *s = source;
	for (size_t i = 0; i < n; i++){
		s[i] = (unsigned char)value;
	}
	return source;
}
