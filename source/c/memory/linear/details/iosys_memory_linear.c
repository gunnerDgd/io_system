#include <io_system/memory/linear/details/iosys_memory_linear.h>
#include <stdlib.h>

__synapse_iosys_memory_linear*
__synapse_iosys_memory_linear_initialize(size_t pBlockSize, synapse_io_system_memory_alloc_model* pAllocModel)
{
	__synapse_iosys_memory_linear* ptr_linear
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, sizeof(__synapse_iosys_memory_linear));

	ptr_linear->entry 
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, sizeof(__synapse_iosys_memory_linear));
	ptr_linear->alloc_model		 = pAllocModel;
	ptr_linear->alloc_block_size = pBlockSize ;

	ptr_linear->entry->node.node_ptr 
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, pBlockSize);
	ptr_linear->entry->node.node_size
		= pBlockSize;

	ptr_linear->backmost = ptr_linear->entry;

	return ptr_linear;
}

void
__synapse_iosys_memory_linear_cleanup(__synapse_iosys_memory_linear* pMmodel)
{
	
}

size_t
__synapse_iosys_memory_linear_total_size(__synapse_iosys_memory_linear* pMmodel)
{
	return pMmodel->total_size;
}