#pragma once
#include <io_system/memory/alloc/alloc_model.h>

synapse_io_system_memory_alloc_model*
synapse_io_system_memory_standard_aligned_heap_initialize(size_t);

void
synapse_io_system_memory_standard_aligned_heap_cleanup   (synapse_io_system_memory_alloc_model*);