// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0){
		return NULL;
	}
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED){ 
		return NULL;
	}
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
	if (nmemb == 0 || size == 0 || total_size / size != nmemb){
		return NULL;
	}
	void *ptr = malloc(total_size);
	if (ptr != NULL){
		memset(ptr, 0, total_size);
	}
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL){
		return;
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL){
		return malloc(size);
	}
	if (size == 0){
		free(ptr);
		return NULL;
	}
	void *new_ptr = malloc(size);
	if (new_ptr != NULL){
		memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0 || (nmemb * size) / size != nmemb){
		return NULL;
	}
	return realloc(ptr, nmemb * size);
}

