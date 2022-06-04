#pragma once
#include <io_system/memory/alloc/alloc_model.h>

typedef struct __synapse_iosys_memory_standard_aligned_heap
{
	uint64_t align_length;
} __synapse_iosys_memory_standard_aligned_heap;

__synapse_iosys_memory_standard_aligned_heap*
__synapse_iosys_memory_standard_aligned_heap_initialize(size_t);

void
__synapse_iosys_memory_standard_aligned_heap_cleanup   (__synapse_iosys_memory_standard_aligned_heap*);

void*
__synapse_iosys_memory_standard_aligned_heap_allocate  (__synapse_iosys_memory_standard_aligned_heap*, void*, size_t);

void
__synapse_iosys_memory_standard_aligned_heap_deallocate(__synapse_iosys_memory_standard_aligned_heap*, void*, size_t);

void*
__synapse_iosys_memory_standard_aligned_heap_resize	   (__synapse_iosys_memory_standard_aligned_heap*, void*, size_t);