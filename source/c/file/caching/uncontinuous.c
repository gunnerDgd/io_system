#include <io_system/file/caching/uncontinuous.h>
#include <io_system/file/details/caching/iosys_file_caching_uncontinuous.h>

#include <stdlib.h>

synapse_iosys_cached_base*
synapse_iosys_file_caching_uncontinuous_initialize(synapse_iosys_base*						pIoBase		 ,
												   synapse_iosys_uncontinuous_memory_model* pIoReadBuffer, 
												   synapse_iosys_uncontinuous_memory_model* pIoWriteBuffer)
{
	synapse_iosys_cached_base* ptr_cache_base
		= malloc(sizeof(synapse_iosys_cached_base));

	ptr_cache_base->base_io_system		 = pIoBase;
	ptr_cache_base->cache_entity		 = __synapse_iosys_file_caching_uncontinuous_initialize(pIoReadBuffer, pIoWriteBuffer);
	
	ptr_cache_base->cached_read			 = &synapse_iosys_file_caching_uncontinuous_read_from		 ;
	ptr_cache_base->cached_read_reserve  = &synapse_iosys_file_caching_uncontinuous_read_from_reserve;
	
	ptr_cache_base->cached_write		 = &synapse_iosys_file_caching_uncontinuous_write_to		 ;
	ptr_cache_base->cached_write_reserve = &synapse_iosys_file_caching_uncontinuous_write_to_reserve ;

	return ptr_cache_base;
}

void
synapse_iosys_file_caching_uncontinuous_cleanup(synapse_iosys_cached_base* pEntity)
{
	__synapse_iosys_file_caching_uncontinuous_cleanup(pEntity->base_io_system, pEntity->cache_entity);
}

size_t
synapse_iosys_file_caching_uncontinuous_read_from(synapse_iosys_cached_base* pEntity, void* pReadBuffer, size_t pReadSize)
{
	return __synapse_iosys_file_caching_uncontinuous_read_from(pEntity->base_io_system,
															   pEntity->cache_entity  ,
															   pReadBuffer			  ,
															   pReadSize);
}

size_t
synapse_iosys_file_caching_uncontinuous_read_from_reserve(synapse_iosys_cached_base* pEntity, size_t pReadSize)
{
	return __synapse_iosys_file_caching_uncontinuous_caching_read_from(pEntity->base_io_system,
																	   pEntity->cache_entity  ,
																	   pReadSize);
}

size_t
synapse_iosys_file_caching_uncontinuous_write_to(synapse_iosys_cached_base* pEntity, void* pWriteBuffer, size_t pWriteSize)
{
	return __synapse_iosys_file_caching_uncontinuous_write_to(pEntity->base_io_system,
															  pEntity->cache_entity  ,
															  pWriteBuffer			 ,
															  pWriteSize);
}

size_t
synapse_iosys_file_caching_uncontinuous_write_to_reserve(synapse_iosys_cached_base* pEntity, size_t pWriteSize)
{
	return __synapse_iosys_file_caching_uncontinuous_caching_write_to(pEntity->base_io_system,
																	  pEntity->cache_entity	,
																	  pWriteSize);
}