#include <io_system/memory/linear/details/iosys_memory_linear_alloc.h>

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_allocate_back(__synapse_iosys_memory_linear* pMmodel)
{
	__synapse_iosys_memory_linear_node* ptr_node
		= synapse_io_system_memory_alloc_model_allocate((*pMmodel->alloc_model), NULL, pMmodel->alloc_block_size);

	ptr_node->node.node_ptr
		= synapse_io_system_memory_alloc_model_allocate((*pMmodel->alloc_model), NULL, pMmodel->alloc_block_size);

	ptr_node->next = NULL;
	ptr_node->prev = pMmodel->backmost;
	
	pMmodel->backmost->next =  ptr_node;
	pMmodel->backmost		=  ptr_node;
	pMmodel->total_size	    += pMmodel->alloc_block_size;

	return ptr_node;
}

__synapse_iosys_memory_linear_node*
__synapse_iosys_memory_linear_allocate_front(__synapse_iosys_memory_linear* pMmodel)
{
	__synapse_iosys_memory_linear_node* ptr_node
		= synapse_io_system_memory_alloc_model_allocate((*pMmodel->alloc_model), NULL, pMmodel->alloc_block_size);

	ptr_node->node.node_ptr
		= synapse_io_system_memory_alloc_model_allocate((*pMmodel->alloc_model), NULL, pMmodel->alloc_block_size);
	
	ptr_node->prev = NULL;
	ptr_node->next = pMmodel->entry;
					 pMmodel->entry		  = ptr_node;
					 pMmodel->total_size += pMmodel->alloc_block_size;

	return ptr_node;
}

void
__synapse_iosys_memory_linear_deallocate_back(__synapse_iosys_memory_linear* pMmodel)
{
	__synapse_iosys_memory_linear_node* ptr_dealloc
		= pMmodel->backmost;

	if  (!pMmodel->backmost->prev) return;
		  pMmodel->backmost = ptr_dealloc->prev;
							  ptr_dealloc->prev->next = NULL;
	
	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		  ,
													  ptr_dealloc->node.node_ptr  ,
													  ptr_dealloc->node.node_size);

	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		,
													  ptr_dealloc,
													  sizeof(__synapse_iosys_memory_linear_node));

	pMmodel->total_size -= pMmodel->alloc_block_size;
}

void
__synapse_iosys_memory_linear_deallocate_front(__synapse_iosys_memory_linear* pMmodel)
{
	__synapse_iosys_memory_linear_node* ptr_dealloc
		= pMmodel->entry;

	if  (!pMmodel->entry->next) return;
		  pMmodel->entry = ptr_dealloc->next;
						   ptr_dealloc->prev->next = NULL;
	
	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		,
													  ptr_dealloc->node.node_ptr,
													  ptr_dealloc->node.node_size);

	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		,
													  ptr_dealloc,
													  sizeof(__synapse_iosys_memory_linear_node));

	pMmodel->total_size -= pMmodel->alloc_block_size;
}

void
__synapse_iosys_memory_linear_deallocate_node(__synapse_iosys_memory_linear* pMmodel, __synapse_iosys_memory_linear_node* pNode)
{
	if (!pNode->prev) { __synapse_iosys_memory_linear_deallocate_front(pMmodel); return; }
	if (!pNode->next) { __synapse_iosys_memory_linear_deallocate_back (pMmodel); return; }

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		,
													  pNode->node.node_ptr,
													  pNode->node.node_size);

	synapse_io_system_memory_alloc_model_deallocate((*pMmodel->alloc_model)		,
													  pNode,
													  sizeof(__synapse_iosys_memory_linear_node));

	pMmodel->total_size -= pMmodel->alloc_block_size;
}