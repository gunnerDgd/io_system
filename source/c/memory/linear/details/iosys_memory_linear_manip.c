#include <io_system/memory/linear/details/iosys_memory_linear_manip.h>
#include <string.h>

size_t
__synapse_iosys_memory_linear_copy_from(__synapse_iosys_memory_linear* pMmodel, uint8_t* pReadMemory, size_t pReadSize)
{
	pReadSize = (pMmodel->total_size > pReadSize) 
			  ?  pReadSize 
			  :  pMmodel->total_size;

	for(__synapse_iosys_memory_linear_node* ptr_seek = pMmodel->entry			  ;
											pReadSize > 0						  ;
											pReadSize   -= pMmodel ->alloc_block_size,
											pReadMemory += pMmodel ->alloc_block_size,
											ptr_seek     = ptr_seek->next)
		memcpy(ptr_seek->node.node_ptr, pReadMemory, (pReadSize > pMmodel->alloc_block_size) 
															    ? pMmodel->alloc_block_size 
																: pReadSize);

	return pReadSize;
}

size_t
__synapse_iosys_memory_linear_copy_to(__synapse_iosys_memory_linear* pMmodel, uint8_t* pWriteMemory, size_t pWriteSize)
{
	pWriteSize = (pMmodel->total_size > pWriteSize)
			   ?  pWriteSize 
			   :  pMmodel->total_size;

	for(__synapse_iosys_memory_linear_node* ptr_seek = pMmodel->entry			  ;
											pWriteSize > 0						  ;
											pWriteSize   -= pMmodel ->alloc_block_size,
											pWriteMemory += pMmodel ->alloc_block_size,
											ptr_seek     = ptr_seek->next)
		memcpy(pWriteMemory, ptr_seek->node.node_ptr, (pWriteSize > pMmodel->alloc_block_size)
																  ? pMmodel->alloc_block_size 
																  : pWriteSize);

	return pWriteSize;
}

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate(__synapse_iosys_memory_linear* pMmodel)
{
	return pMmodel->entry;
}

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_iterate_next(__synapse_iosys_memory_linear_node* pNode)
{
	return pNode->next;
}