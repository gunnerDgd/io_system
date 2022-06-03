#include <io_system/file/details/iosys_file_uncontinuous.h>

#include <Windows.h>
#include <stdlib.h>

size_t
__synapse_iosys_file_uncontinuous_io_model_caching_read_from(__synapse_iosys_file_uncontinuous_io_model* pIoModel, size_t pReadSize)
{
	synapse_iosys_uncontinuous_memory_model		 *ptr_rdcache	   = pIoModel->io_read_cache;
	synapse_iosys_uncontinuous_memory_model_node* ptr_rdcache_node = ptr_rdcache->iterate(ptr_rdcache->mmodel.entity);
	
	DWORD										  sz_read_round    = 0,
												  sz_read_total	   = 0;

	pIoModel->io_read_cached_pointer = pIoModel->io_pointer;
	pIoModel->io_read_cached		 = pReadSize;

	if (ptr_rdcache->total_size(ptr_rdcache->mmodel.entity) < pReadSize)
		ptr_rdcache->allocate  (ptr_rdcache->mmodel.entity, pReadSize);

	for (; pReadSize		  
		 ; ptr_rdcache_node = ptr_rdcache->iterate_next(ptr_rdcache->mmodel.entity, ptr_rdcache_node))
	{
		
		ReadFile(pIoModel->io_entity		  ,
				 ptr_rdcache_node->node_ptr,
				 ptr_rdcache_node->node_size, &sz_read_round, NULL);

		if (sz_read_round < ptr_rdcache_node)
			return sz_read_total;

		pReadSize     -= ptr_rdcache_node->node_size;
		sz_read_total += sz_read_round;
	}

	return sz_read_total;
}

size_t
__synapse_iosys_file_uncontinuous_io_model_caching_write_to(__synapse_iosys_file_uncontinuous_io_model* pIoModel, size_t pWriteSize)
{
	synapse_iosys_uncontinuous_memory_model	     *ptr_wrcache	   = pIoModel->io_write_cache;
	synapse_iosys_uncontinuous_memory_model_node *ptr_wrcache_node = ptr_wrcache->iterate(ptr_wrcache->mmodel.entity);
	DWORD										  sz_write_round   = 0;

	pWriteSize = (pWriteSize > ptr_wrcache->total_size(ptr_wrcache->mmodel.entity))
			   ?			   ptr_wrcache->total_size(ptr_wrcache->mmodel.entity)
		       :			   pWriteSize;

	for ( ; pWriteSize 
		  ; ptr_wrcache_node = ptr_wrcache->iterate_next(ptr_wrcache->mmodel.entity, ptr_wrcache_node))
	{
		WriteFile(pIoModel->io_entity, ptr_wrcache_node->node_ptr, 
											ptr_wrcache_node->node_size, &sz_write_round, NULL);
		pWriteSize -= ptr_wrcache_node->node_size;
	}

	return pWriteSize;
}