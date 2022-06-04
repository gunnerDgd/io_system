#pragma once
#include <io_system/memory/alloc/alloc_model.h>

void* __synapse_iosys_memory_standard_heap_allocate  (void*, void*, size_t);
void  __synapse_iosys_memory_standard_heap_deallocate(void*, void*, size_t);
void* __synapse_iosys_memory_standard_heap_resize    (void*, void*, size_t);