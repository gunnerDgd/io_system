#pragma once
#include <io_system/memory/uncontinuous_model.h>
#include <io_system/memory/alloc/alloc_model.h>

synapse_iosys_uncontinuous_memory_model* 
synapse_iosys_memory_linear_initialize(size_t, synapse_io_system_memory_alloc_model*);

void
synapse_iosys_memory_linear_cleanup   (synapse_iosys_uncontinuous_memory_model*)     ;

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate	  (void*, size_t);

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate_back (void*);

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate_front(void*);

void
synapse_iosys_memory_linear_deallocate	    (void*, synapse_iosys_uncontinuous_memory_model_node*);

void
synapse_iosys_memory_linear_deallocate_back (void*);

void
synapse_iosys_memory_linear_deallocate_front(void*);

size_t
synapse_iosys_memory_linear_total_size		(void*);

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_iterate(void*);

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_iterate_next(void*, synapse_iosys_uncontinuous_memory_model_node*);

size_t
synapse_iosys_memory_linear_copy_from(void*, void*, size_t, size_t);

size_t
synapse_iosys_memory_linear_copy_to  (void*, void*, size_t, size_t);