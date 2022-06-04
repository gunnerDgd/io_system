#include <io_system/memory/alloc/details/standard_library/iosys_memory_standard_aligned_heap.h>
#include <stdlib.h>

__synapse_iosys_memory_standard_aligned_heap*
__synapse_iosys_memory_standard_aligned_heap_initialize(size_t pAlign)
{
	__synapse_iosys_memory_standard_aligned_heap* ptr_entity
		= malloc(sizeof(__synapse_iosys_memory_standard_aligned_heap));

	ptr_entity->align_length = pAlign;
	return ptr_entity;
}

void
__synapse_iosys_memory_standard_aligned_heap_cleanup(__synapse_iosys_memory_standard_aligned_heap*);

void*
__synapse_iosys_memory_standard_aligned_heap_allocate(__synapse_iosys_memory_standard_aligned_heap* pEntity, void* pHint, size_t pAllocSize)
{
	return _aligned_malloc(pAllocSize, pEntity->align_length);
}

void
__synapse_iosys_memory_standard_aligned_heap_deallocate(__synapse_iosys_memory_standard_aligned_heap* pEntity, void* pHint, size_t pAllocSize)
{
	_aligned_free(pHint);
}

void*
__synapse_iosys_memory_standard_aligned_heap_resize(__synapse_iosys_memory_standard_aligned_heap* pEntity, void* pResize, size_t pNewSize)
{
	return _aligned_realloc(pResize, pNewSize, pEntity->align_length);
}