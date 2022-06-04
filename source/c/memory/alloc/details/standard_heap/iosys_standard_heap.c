#include <io_system/memory/alloc/details/standard_library/iosys_memory_standard_heap.h>
#include <stdlib.h>

void* __synapse_iosys_memory_standard_heap_allocate(void* pEntity, void* pHint, size_t pSize)
{
	return malloc(pSize);
}

void  __synapse_iosys_memory_standard_heap_deallocate(void* pEntity, void* pDealloc, size_t pSize)
{
	free(pDealloc);
}

void* __synapse_iosys_memory_standard_heap_resize(void* pEntity, void* pHint, size_t pSize)
{
	return realloc(pHint, pSize);
}