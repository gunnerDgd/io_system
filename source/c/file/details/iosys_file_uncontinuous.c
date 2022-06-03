#include <io_system/file/details/iosys_file_uncontinuous.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_iosys_file_uncontinuous_io_model*
__synapse_iosys_file_uncontinuous_io_model_initialize_open(const char*								pFileName  , 
														   synapse_iosys_uncontinuous_memory_model* pReadCache ,
														   synapse_iosys_uncontinuous_memory_model* pWriteCache)
{
	__synapse_iosys_file_uncontinuous_io_model* ptr_iomodel 
		= malloc(sizeof(__synapse_iosys_file_uncontinuous_io_model));

	ptr_iomodel->io_entity	     = CreateFileA(pFileName, GENERIC_ALL, 0, 0, OPEN_EXISTING, 0, 0);
	ptr_iomodel->io_pointer		 = 0;

	ptr_iomodel->io_read_cache			 = pReadCache ;
	ptr_iomodel->io_read_cached			 = 0		  ;
	ptr_iomodel->io_read_cached_pointer  = 0		  ;

	ptr_iomodel->io_write_cache			 = pWriteCache;
	ptr_iomodel->io_write_cached		 = 0		  ;
	ptr_iomodel->io_write_cached_pointer = 0		  ;

	return ptr_iomodel;
}

void
__synapse_iosys_file_uncontinuous_io_model_cleanup(__synapse_iosys_file_uncontinuous_io_model* pIoModel)
{

}

size_t
__synapse_iosys_file_uncontinuous_io_model_read_from(__synapse_iosys_file_uncontinuous_io_model* pIoModel, uint8_t* pReadBuffer, size_t pReadSize)
{
	if ()
	{
		
	}
}

size_t
__synapse_iosys_file_uncontinuous_io_model_write_to(__synapse_iosys_file_uncontinuous_io_model* pIoModel, uint8_t* pWriteBuffer, size_t pWriteSize)
{

}