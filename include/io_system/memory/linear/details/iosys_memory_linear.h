#pragma once
#include <io_system/memory/model.h>
#include <io_system/memory/alloc/alloc_model.h>

typedef struct __synapse_iosys_memory_linear_node
{
	synapse_iosys_uncontinuous_memory_model_node node;

	struct __synapse_iosys_memory_linear_node   *next,
												*prev;
} __synapse_iosys_memory_linear_node;

typedef struct __synapse_iosys_memory_linear
{
	size_t								  total_size	  ;

	size_t								  alloc_block_size;
	synapse_io_system_memory_alloc_model *alloc_model	  ;
	
	__synapse_iosys_memory_linear_node   *entry			  ,
										 *backmost		  ;
} __synapse_iosys_memory_linear;

__synapse_iosys_memory_linear*
__synapse_iosys_memory_linear_initialize	  (size_t, synapse_io_system_memory_alloc_model*);

void
__synapse_iosys_memory_linear_cleanup		  (__synapse_iosys_memory_linear*);

size_t
__synapse_iosys_memory_linear_total_size	  (__synapse_iosys_memory_linear*);