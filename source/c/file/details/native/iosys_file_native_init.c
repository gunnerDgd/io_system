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
__synapse_iosys_file_native_initialize_open_existing(const wchar_t* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFile(pName, GENERIC_ALL, 0, 0, OPEN_ALWAYS, FILE_FLAG_OVERLAPPED, 0);
	
	memset(&ptr_iosys->hnd_aio, 0x00, sizeof(OVERLAPPED));
			ptr_iosys->hnd_aio.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	return	ptr_iosys;
}

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_create_new(const wchar_t* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFile(pName, GENERIC_ALL, 0, 0, CREATE_NEW, FILE_FLAG_OVERLAPPED, 0);

	memset(&ptr_iosys->hnd_aio, 0x00, sizeof(OVERLAPPED));
			ptr_iosys->hnd_aio.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	return  ptr_iosys;
}

__synapse_iosys_file_native*
__synapse_iosys_file_vectorized_initialize_open_existing(const wchar_t* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFile(pName, GENERIC_ALL, 0, 0, OPEN_ALWAYS, FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING, 0);
	
	memset(&ptr_iosys->hnd_aio, 0x00, sizeof(OVERLAPPED));
			ptr_iosys->hnd_aio.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	return	ptr_iosys;
}

__synapse_iosys_file_native*
__synapse_iosys_file_vectorized_initialize_create_new(const wchar_t* pName)
{
	__synapse_iosys_file_native* 
		ptr_iosys 
			= malloc(sizeof(__synapse_iosys_file_native));
		ptr_iosys->hnd_file 
			= CreateFile(pName, GENERIC_ALL, 0, 0, CREATE_NEW, FILE_FLAG_OVERLAPPED | FILE_FLAG_NO_BUFFERING, 0);

	memset(&ptr_iosys->hnd_aio, 0x00, sizeof(OVERLAPPED));
			ptr_iosys->hnd_aio.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	return  ptr_iosys;
}