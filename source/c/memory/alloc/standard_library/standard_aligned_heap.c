#include <io_system/memory/alloc/standard_library/standard_aligned_heap.h>
#include <io_system/memory/alloc/details/standard_library/iosys_memory_standard_aligned_heap.h>

#include <stdlib.h>

synapse_io_system_memory_alloc_model*
synapse_io_system_memory_standard_aligned_heap_initialize(size_t pAlignByte)
{
	synapse_io_system_memory_alloc_model* ptr_alloc =
		malloc(sizeof(synapse_io_system_memory_alloc_model));

	ptr_alloc->allocate   = &__synapse_iosys_memory_standard_aligned_heap_allocate  ;
	ptr_alloc->deallocate = &__synapse_iosys_memory_standard_aligned_heap_deallocate;
	ptr_alloc->resize	  = &__synapse_iosys_memory_standard_aligned_heap_resize    ;
	ptr_alloc->entity     =  __synapse_iosys_memory_standard_aligned_heap_initialize(pAlignByte);

	return ptr_alloc;
}

void
synapse_io_system_memory_standard_aligned_heap_cleanup(synapse_io_system_memory_alloc_model* pAllocModel)
{
	__synapse_iosys_memory_standard_aligned_heap_cleanup(pAllocModel->entity);
	free											    (pAllocModel)		 ;
}