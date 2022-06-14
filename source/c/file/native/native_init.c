#include <io_system/file/native/native_init.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <stdlib.h>

synapse_io_system_file*
synapse_iosys_file_native_initialize_open_existing(const wchar_t* pName)
{
	synapse_io_system_file* ptr_iosys_base					 = malloc(sizeof(synapse_io_system_file));
							ptr_iosys_base->handle.opaque    = __synapse_iosys_file_native_initialize_open_existing(pName);
						
							ptr_iosys_base->read_from		 = &synapse_iosys_file_native_read_from		  ;
							ptr_iosys_base->read_from_vector = &synapse_iosys_file_native_read_from_vector;
							
							ptr_iosys_base->write_to		 = &synapse_iosys_file_native_write_to		 ;
							ptr_iosys_base->write_to_vector  = &synapse_iosys_file_native_write_to_vector;

							ptr_iosys_base->current_pointer  = &synapse_iosys_file_native_pointer_current ;
							ptr_iosys_base->move_pointer     = &synapse_iosys_file_native_pointer_set     ;
							ptr_iosys_base->wait_until		 = &synapse_iosys_file_native_wait_until	  ;

	return ptr_iosys_base;
}

synapse_io_system_file*
synapse_iosys_file_native_initialize_create_new(const wchar_t* pName)
{
	synapse_io_system_file* ptr_iosys_base					 = malloc(sizeof(synapse_io_system_file));
							ptr_iosys_base->handle.opaque	 = __synapse_iosys_file_native_initialize_create_new(pName);
						
							ptr_iosys_base->read_from		 = &synapse_iosys_file_native_read_from		  ;
							ptr_iosys_base->read_from_vector = &synapse_iosys_file_native_read_from_vector;
							
							ptr_iosys_base->write_to		 = &synapse_iosys_file_native_write_to		 ;
							ptr_iosys_base->write_to_vector  = &synapse_iosys_file_native_write_to_vector;

							ptr_iosys_base->current_pointer  = &synapse_iosys_file_native_pointer_current ;
							ptr_iosys_base->move_pointer     = &synapse_iosys_file_native_pointer_set     ;
							ptr_iosys_base->wait_until		 = &synapse_iosys_file_native_wait_until	  ;

	return ptr_iosys_base;
}

void
synapse_iosys_file_native_cleanup(synapse_io_system_file* pIoBase)
{
	__synapse_iosys_file_native_cleanup(pIoBase->handle.opaque);
	free(pIoBase);
}