#pragma once
#include <io_system/memory/alloc/alloc_model.h>
#include <io_system/memory/alloc/system_paging/system_paging_type.h>

synapse_io_system_memory_alloc_model
__synapse_io_system_memory_system_paging_initialize(int);

void*
__synapse_io_system_memory_system_paging_allocate   (void*, void*, size_t);

void*
__synapse_io_system_memory_system_paging_allocate_4m(void*, void*, size_t);

void*
__synapse_io_system_memory_system_paging_allocate_1g(void*, void*, size_t);

void
__synapse_io_system_memory_system_paging_deallocate (void*, void*, size_t);