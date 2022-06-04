#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <stdlib.h>

synapse_iosys_base*
synapse_iosys_file_native_initialize_open_existing(const char* pName)
{
	synapse_iosys_base* ptr_iosys_base					= malloc(sizeof(synapse_iosys_base));
						ptr_iosys_base->ptr_entity		= __synapse_iosys_file_native_initialize_open_existing(pName);
						
						ptr_iosys_base->read_from		= &synapse_iosys_file_native_read_from;
						ptr_iosys_base->write_to		= &synapse_iosys_file_native_write_to ;

						ptr_iosys_base->pointer_current = &synapse_iosys_file_native_pointer_current;
						ptr_iosys_base->pointer_set		= &synapse_iosys_file_native_pointer_set    ;

	return ptr_iosys_base;
}

synapse_iosys_base*
synapse_iosys_file_native_initialize_create_new(const char* pName)
{
	synapse_iosys_base* ptr_iosys_base					= malloc(sizeof(synapse_iosys_base));
						ptr_iosys_base->ptr_entity		= __synapse_iosys_file_native_initialize_create_new(pName);
						
						ptr_iosys_base->read_from		= &synapse_iosys_file_native_read_from;
						ptr_iosys_base->write_to		= &synapse_iosys_file_native_write_to ;

						ptr_iosys_base->pointer_current = &synapse_iosys_file_native_pointer_current;
						ptr_iosys_base->pointer_set		= &synapse_iosys_file_native_pointer_set	;

	return ptr_iosys_base;
}

void
synapse_iosys_file_native_cleanup(synapse_iosys_base* pIoBase)
{
	__synapse_iosys_file_native_cleanup(pIoBase->ptr_entity);
	free(pIoBase);
}

size_t
synapse_iosys_file_native_read_from(void* pEntity, void* pReadBuffer, size_t pReadSize)
{
	return __synapse_iosys_file_native_read_from(pEntity, pReadBuffer, pReadSize);
}

size_t
synapse_iosys_file_native_write_to(void* pEntity, void* pWriteBuffer, size_t pWriteSize)
{
	return __synapse_iosys_file_native_write_to (pEntity, pWriteBuffer, pWriteSize);
}

size_t
synapse_iosys_file_native_pointer_current(void* pEntity)
{
	return __synapse_iosys_file_native_pointer_current(pEntity);
}

size_t
synapse_iosys_file_native_pointer_set(void* pEntity, size_t pNewPointer)
{
	return __synapse_iosys_file_native_pointer_set(pEntity, pNewPointer);
}