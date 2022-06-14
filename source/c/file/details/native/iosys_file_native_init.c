#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <Windows.h>

void
__synapse_iosys_file_native_cleanup(__synapse_iosys_file_native* pNative)
{
	CloseHandle(pNative->hnd_file);
	free	   (pNative);
}

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_open_existing(const char* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFileA(pName, GENERIC_ALL, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
		
	return	ptr_iosys;
}

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_create_new(const char* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFileA(pName, GENERIC_ALL, 0, 0, CREATE_NEW, FILE_FLAG_OVERLAPPED, 0);
	return ptr_iosys;
}