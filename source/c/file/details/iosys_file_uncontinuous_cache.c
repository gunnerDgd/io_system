#include <io_system/file/details/caching/iosys_file_caching_uncontinuous.h>
#include <stdlib.h>

size_t
__synapse_iosys_file_caching_uncontinuous_caching_read_from(synapse_iosys_base* pIoBase, __synapse_iosys_file_caching_uncontinuous* pIoModel, size_t pReadSize)
{
	synapse_iosys_uncontinuous_memory_model		 *ptr_rdcache	   = pIoModel->io_read_cache;
	synapse_iosys_uncontinuous_memory_model_node *ptr_rdcache_node = ptr_rdcache->iterate(ptr_rdcache->mmodel.entity);
	
	size_t										  sz_read_round    = 0,
												  sz_read_total	   = 0;

	synapse_iosys_base_pointer_set((*pIoBase), pIoModel->io_read_pointer);
											   pIoModel->io_read_cached_pointer = pIoModel->io_read_pointer;
											   pIoModel->io_read_cached		    = pReadSize;

	if (ptr_rdcache->total_size(ptr_rdcache->mmodel.entity) < pReadSize)
		ptr_rdcache->allocate  (ptr_rdcache->mmodel.entity, pReadSize);

	for (; pReadSize		  
		 ; ptr_rdcache_node = ptr_rdcache->iterate_next(ptr_rdcache->mmodel.entity, ptr_rdcache_node))
	{
		sz_read_round = 
			synapse_iosys_base_read_from((*pIoBase), ptr_rdcache_node->node_ptr, ptr_rdcache_node->node_size);

		if (sz_read_round < ptr_rdcache_node->node_size) // End of File Reached.
			return sz_read_total;

		pIoModel->io_read_pointer += sz_read_round;
		sz_read_total			  += sz_read_round;
		pReadSize				  -= ptr_rdcache_node->node_size;
	}

	return sz_read_total;
}

size_t
__synapse_iosys_file_caching_uncontinuous_caching_write_to(synapse_iosys_base* pIoBase, __synapse_iosys_file_caching_uncontinuous* pIoModel, size_t pWriteSize)
{
	synapse_iosys_uncontinuous_memory_model	     *ptr_wrcache	   = pIoModel->io_write_cache;
	synapse_iosys_uncontinuous_memory_model_node *ptr_wrcache_node = ptr_wrcache->iterate(ptr_wrcache->mmodel.entity);
	size_t										  sz_write_round   = 0;

	pWriteSize = (pWriteSize > synapse_iosys_uncontinuous_memory_model_total_size((*ptr_wrcache)))
			   ?			   synapse_iosys_uncontinuous_memory_model_total_size((*ptr_wrcache))
			   :			   pWriteSize;

	for ( ; ptr_wrcache_node && pWriteSize 
		  ; ptr_wrcache_node = ptr_wrcache->iterate_next(ptr_wrcache->mmodel.entity, ptr_wrcache_node))
	{
		sz_write_round = 
			synapse_iosys_base_write_to((*pIoBase), ptr_wrcache_node->node_ptr, ptr_wrcache_node->node_size);
		
		pWriteSize				   -= ptr_wrcache_node->node_size;
		pIoModel->io_write_pointer += ptr_wrcache_node->node_size;
	}

	return pWriteSize;
}