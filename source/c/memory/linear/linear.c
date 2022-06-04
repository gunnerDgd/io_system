#include <io_system/memory/linear/linear.h>

#include <io_system/memory/linear/details/iosys_memory_linear.h>
#include <io_system/memory/linear/details/iosys_memory_linear_alloc.h>
#include <io_system/memory/linear/details/iosys_memory_linear_manip.h>

synapse_iosys_uncontinuous_memory_model* 
synapse_iosys_memory_linear_initialize(size_t pBlockSize, synapse_io_system_memory_alloc_model* pAlloc)
{
	__synapse_iosys_memory_linear* ptr_linear
		= __synapse_iosys_memory_linear_initialize(pBlockSize, pAlloc);

	synapse_iosys_uncontinuous_memory_model* ptr_mmodel
		= synapse_io_system_memory_alloc_model_allocate((*pAlloc), NULL, sizeof(synapse_iosys_uncontinuous_memory_model));

	ptr_mmodel->allocate		 = &synapse_iosys_memory_linear_allocate	  ;
	ptr_mmodel->allocate_back    = &synapse_iosys_memory_linear_allocate_back ;
	ptr_mmodel->allocate_front   = &synapse_iosys_memory_linear_allocate_front;

	ptr_mmodel->deallocate       = &synapse_iosys_memory_linear_deallocate		;
	ptr_mmodel->deallocate_back  = &synapse_iosys_memory_linear_deallocate_back ;
	ptr_mmodel->deallocate_front = &synapse_iosys_memory_linear_deallocate_front;

	ptr_mmodel->iterate			 = &synapse_iosys_memory_linear_iterate		;
	ptr_mmodel->iterate_next	 = &synapse_iosys_memory_linear_iterate_next;
	ptr_mmodel->iterate_at		 = &synapse_iosys_memory_linear_iterate_at  ;

	ptr_mmodel->total_size		 = &synapse_iosys_memory_linear_total_size  ;
	ptr_mmodel->mmodel.copy_from = &synapse_iosys_memory_linear_copy_from   ;
	ptr_mmodel->mmodel.copy_to   = &synapse_iosys_memory_linear_copy_to     ;

	ptr_mmodel->mmodel.entity	 = ptr_linear;

	return ptr_mmodel;
}

void									 
synapse_iosys_memory_linear_cleanup(synapse_iosys_uncontinuous_memory_model*);

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate(void* pEntity, size_t pSize)
{
	size_t sz_block = ((__synapse_iosys_memory_linear*)pEntity)->alloc_block_size,
		   sz_cnt   = (sz_block / pSize) + 1;

	for (size_t i = 0; i < sz_cnt; i++)
		__synapse_iosys_memory_linear_allocate_back(pEntity);
}

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate_back (void* pEntity) { return __synapse_iosys_memory_linear_allocate_back (pEntity); }

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_allocate_front(void* pEntity) { return __synapse_iosys_memory_linear_allocate_front(pEntity); }

void
synapse_iosys_memory_linear_deallocate(void* pEntity, synapse_iosys_uncontinuous_memory_model_node* pNode)
{
	__synapse_iosys_memory_linear_deallocate_node(pEntity, pNode);
}

void
synapse_iosys_memory_linear_deallocate_back(void* pEntity)
{
	__synapse_iosys_memory_linear_deallocate_back(pEntity);
}

void
synapse_iosys_memory_linear_deallocate_front(void* pEntity)
{
	__synapse_iosys_memory_linear_deallocate_front(pEntity);
}

size_t
synapse_iosys_memory_linear_total_size(void* pEntity)
{
	return __synapse_iosys_memory_linear_total_size(pEntity);
}

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_iterate(void* pEntity)
{
	return __synapse_iosys_memory_linear_iterate(pEntity);
}

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_iterate_next(void* pEntity, synapse_iosys_uncontinuous_memory_model_node* pNode)
{
	return __synapse_iosys_memory_linear_iterate_next(pNode);
}

synapse_iosys_uncontinuous_memory_model_node*
synapse_iosys_memory_linear_iterate_at(void* pEntity, size_t pPointer)
{
	return __synapse_iosys_memory_linear_seek(pEntity, pPointer);
}

size_t
synapse_iosys_memory_linear_copy_from(void* pEntity, void* pReadMemory, size_t pReadSize, size_t pReadPointer)
{
	return __synapse_iosys_memory_linear_copy_from(pEntity, pReadMemory, pReadSize, pReadPointer);
}

size_t
synapse_iosys_memory_linear_copy_to(void* pEntity, void* pWriteMemory, size_t pWriteSize, size_t pWritePointer)
{
	return __synapse_iosys_memory_linear_copy_to(pEntity, pWriteMemory, pWriteSize, pWritePointer);
}