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
	if(size == 0) {
		return NULL;
	}

	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(block == MAP_FAILED) {
    	return NULL;
    }

	if(mem_list_add(block, size) != 0) {
        munmap(block, size);
        return NULL;
    }

    return block;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;

    if(nmemb != 0 && size != total_size / nmemb) {
        return NULL;
    }

    void *block = malloc(total_size);

    if(!block) {
        return NULL;
    }

    memset(block, 0, total_size);

    return block;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

    struct mem_list *item = mem_list_find(ptr);

	munmap(ptr, item->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (!ptr) {
        return malloc(size);
    }

    size_t *old_size = (size_t *)ptr - 1;

    if (*old_size >= size) {
        return ptr;
    }

    void *new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL;
    }

    memcpy(new_ptr, ptr, *old_size);

    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    size_t total_size = nmemb * size;

    return realloc(ptr, total_size);
}
