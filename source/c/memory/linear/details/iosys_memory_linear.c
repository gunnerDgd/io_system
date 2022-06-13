#include <io_system/memory/linear/details/iosys_memory_linear.h>
#include <stdlib.h>

#include <io_system/debug/message/default.h>

__synapse_iosys_memory_linear*
__synapse_iosys_memory_linear_initialize(size_t pBlockSize, synapse_io_system_memory_alloc_model* pAllocModel)
{
	__synapse_iosys_memory_linear* ptr_linear
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, sizeof(__synapse_iosys_memory_linear));

	ptr_linear->entry 
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, sizeof(__synapse_iosys_memory_linear));
	ptr_linear->alloc_model		 = pAllocModel;
	ptr_linear->alloc_block_size = pBlockSize ;

	ptr_linear->entry->node_pointer 
		= synapse_io_system_memory_alloc_model_allocate((*pAllocModel), NULL, pBlockSize);
	ptr_linear->entry->node_size
		= pBlockSize;
	ptr_linear->entry->node_ptr
		= 0;

	ptr_linear->entry->prev = NULL;
	ptr_linear->entry->next = NULL;

	ptr_linear->backmost = ptr_linear->entry;

	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::entry"			  , ptr_linear->entry)			 ;
	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::alloc_model"	  , ptr_linear->alloc_model)	 ;
	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::alloc_block_size", ptr_linear->alloc_block_size);

	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::node::node_ptr"     , ptr_linear->entry->node_ptr)    ;
	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::node::node_size"    , ptr_linear->entry->node_size)   ;
	synapse_iosys_debug_message_value("synapse-iosys-memory::iosys_memory_linear", __FUNCTION__, "__synapse_iosys_memory_linear::node::node_pointer" , ptr_linear->entry->node_pointer);

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