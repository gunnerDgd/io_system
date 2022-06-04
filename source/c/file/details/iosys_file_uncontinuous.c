#include <io_system/file/details/caching/iosys_file_caching_uncontinuous.h>
#include <stdlib.h>

#include <io_system/debug/message/default.h>

__synapse_iosys_file_caching_uncontinuous*
__synapse_iosys_file_caching_uncontinuous_initialize(synapse_iosys_uncontinuous_memory_model* pReadCache ,
													 synapse_iosys_uncontinuous_memory_model* pWriteCache)
{
	__synapse_iosys_file_caching_uncontinuous* ptr_iomodel
		= malloc(sizeof(__synapse_iosys_file_caching_uncontinuous));

	ptr_iomodel->io_read_pointer		 = 0		  ;
	ptr_iomodel->io_write_pointer		 = 0		  ;

	ptr_iomodel->io_read_cache			 = pReadCache ;
	ptr_iomodel->io_read_cached			 = 0		  ;
	ptr_iomodel->io_read_cached_pointer  = 0		  ;

	ptr_iomodel->io_write_cache			 = pWriteCache;
	ptr_iomodel->io_write_cached		 = 0		  ;
	ptr_iomodel->io_write_cached_pointer = 0		  ;

	return ptr_iomodel;
}

void
__synapse_iosys_file_caching_uncontinuous_cleanup(synapse_iosys_base* pIoBase, __synapse_iosys_file_caching_uncontinuous* pIoModel)
{
	__synapse_iosys_file_caching_uncontinuous_caching_write_to(pIoBase, pIoModel, -1);
	free													  (pIoModel);
}

size_t
__synapse_iosys_file_caching_uncontinuous_read_from(synapse_iosys_base* pIoBase, __synapse_iosys_file_caching_uncontinuous* pIoModel, uint8_t* pReadBuffer, size_t pReadSize)
{
	size_t ptr_read = pIoModel->io_read_pointer - 
					  pIoModel->io_read_cached_pointer;

	if ((pIoModel->io_read_cached_pointer + pIoModel->io_read_cached) <
		(pIoModel->io_read_pointer		  + pReadSize))
		__synapse_iosys_file_caching_uncontinuous_caching_read_from(pIoBase, pIoModel, pReadSize * 2);

											  pIoModel->io_read_pointer += pReadSize;
	return synapse_iosys_memory_model_copy_to(pIoModel->io_read_cache->mmodel,
											  pReadBuffer					 ,
											  pReadSize						 ,
											  ptr_read);
}

size_t
__synapse_iosys_file_caching_uncontinuous_write_to(synapse_iosys_base* pIoBase, __synapse_iosys_file_caching_uncontinuous* pIoModel, uint8_t* pWriteBuffer, size_t pWriteSize)
{
	size_t ptr_write = pIoModel->io_write_pointer - 
					   pIoModel->io_write_cached_pointer;

	synapse_iosys_debug_message_value("__synapse_iosys_file_caching_uncontinuous", __FUNCTION__, "ptr_write", ptr_write);
	
	if (pIoModel->io_write_cached < pWriteSize)
	{
		synapse_iosys_debug_message_value("__synapse_iosys_file_caching_uncontinuous", __FUNCTION__, "pIoModel->io_write_cache->mmodel->entity", pIoModel->io_write_cache->mmodel.entity);
		pIoModel->io_write_cache->allocate(pIoModel->io_write_cache->mmodel.entity, pWriteSize);
	}

												pIoModel->io_write_pointer += pWriteSize;
		   synapse_iosys_debug_message_value("__synapse_iosys_file_caching_uncontinuous", __FUNCTION__, "pIoModel->io_write_pointer", pIoModel->io_write_pointer);
	return synapse_iosys_memory_model_copy_from(pIoModel->io_write_cache->mmodel,
											    pWriteBuffer					,
											    pWriteSize						,
												ptr_write);
}