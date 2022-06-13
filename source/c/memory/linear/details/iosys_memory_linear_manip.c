#include <io_system/memory/linear/details/iosys_memory_linear_manip.h>
#include <string.h>

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_seek(__synapse_iosys_memory_linear* pMmodel, size_t pSeekPointer)
{
	__synapse_iosys_memory_linear_node* ptr_seek = pMmodel->entry;

	for(size_t sz_seeked = 0								  ;
			   sz_seeked +  ptr_seek->node_size < pSeekPointer;
			   sz_seeked += ptr_seek->node_size, ptr_seek = ptr_seek->next);

	return ptr_seek;
}

size_t
__synapse_iosys_memory_linear_copy_from(__synapse_iosys_memory_linear* pMmodel, uint8_t* pReadMemory, size_t pReadSize, size_t pReadPointer)
{
	__synapse_iosys_memory_linear_node* ptr_seek = __synapse_iosys_memory_linear_seek(pMmodel, pReadPointer);
	pReadSize = (pMmodel->total_size > (pReadSize + pReadPointer))
			  ?  pReadSize + pReadPointer
			  :  pMmodel->total_size;

	size_t tmp_sz_off_first_copy = (pReadPointer % pMmodel->alloc_block_size);

	memcpy(ptr_seek->node_ptr  + ptr_seek->node_pointer + tmp_sz_off_first_copy, 
									   pReadMemory							   ,
		   ptr_seek->node_size - (pReadPointer % pMmodel->alloc_block_size));

	pReadSize   -= ptr_seek->node.node_size - (pReadPointer % pMmodel->alloc_block_size);
	pReadMemory += ptr_seek->node.node_size - (pReadPointer % pMmodel->alloc_block_size);
				   ptr_seek = ptr_seek->next;

	for(										 ;
		ptr_seek && pReadSize > 0				 ;
		pReadSize   -= (pMmodel ->alloc_block_size - ptr_seek->node_pointer),
		pReadMemory += (pMmodel ->alloc_block_size - ptr_seek->node_pointer),
		ptr_seek     = ptr_seek->next)
	{
		memcpy(ptr_seek->node.node_ptr + ptr_seek->node_pointer, 
			   pReadMemory, (pReadSize > (pMmodel->alloc_block_size - ptr_seek->node_pointer)) 
									   ? (pMmodel->alloc_block_size - ptr_seek->node_pointer)
									   :  pReadSize);

		ptr_seek->node_pointer += (pMmodel->alloc_block_size - ptr_seek->node_pointer);
	}

	return pReadSize;
}

size_t
__synapse_iosys_memory_linear_copy_to(__synapse_iosys_memory_linear* pMmodel, uint8_t* pWriteMemory, size_t pWriteSize, size_t pWritePointer)
{
	__synapse_iosys_memory_linear_node* ptr_seek = __synapse_iosys_memory_linear_seek(pMmodel, pWritePointer);
	pWriteSize = (pMmodel->total_size > pWriteSize)
			   ?  pWriteSize 
			   :  pMmodel->total_size;

	memcpy(pWriteMemory, ptr_seek->node.node_ptr  + (pWritePointer % pMmodel->alloc_block_size),
						 ptr_seek->node.node_size - (pWritePointer % pMmodel->alloc_block_size));

	pWriteSize   -= ptr_seek->node.node_size - (pWritePointer % pMmodel->alloc_block_size);
	pWriteMemory += ptr_seek->node.node_size - (pWritePointer % pMmodel->alloc_block_size);
					ptr_seek = ptr_seek->next;

	for(__synapse_iosys_memory_linear_node* ptr_seek = pMmodel->entry			  ;
											ptr_seek && pWriteSize > 0			  ;

											pWriteSize   -= ptr_seek->node_pointer,
											pWriteMemory += ptr_seek->node_pointer,
											ptr_seek      = ptr_seek->next)
		memcpy(pWriteMemory, ptr_seek->node.node_ptr, (pWriteSize > ptr_seek->node_pointer)
																  ? ptr_seek->node_pointer 
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