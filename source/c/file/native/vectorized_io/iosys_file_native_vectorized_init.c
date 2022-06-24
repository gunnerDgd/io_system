#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_init.h>

__synapse_iosys_file_native_vectorized*
__synapse_iosys_file_native_vectorized_create_new
	(const wchar_t* pName)
{
	__synapse_iosys_file_native_vectorized* ptr_vec
		= malloc(sizeof(__synapse_iosys_file_native_vectorized));

	ptr_vec->hnd_file
		= CreateFile(pName, GENERIC_ALL, 0, NULL, CREATE_NEW, FILE_FLAG_NO_BUFFERING | FILE_FLAG_OVERLAPPED, 0);
	return
		ptr_vec;
}

__synapse_iosys_file_native_vectorized*
__synapse_iosys_file_native_vectorized_open_existing
	(const wchar_t* pName)
{
	__synapse_iosys_file_native_vectorized* ptr_vec
		= malloc(sizeof(__synapse_iosys_file_native_vectorized));

	ptr_vec->hnd_file
		= CreateFile(pName, GENERIC_ALL, 0, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING | FILE_FLAG_OVERLAPPED, 0);
	return
		ptr_vec;
}

void
__synapse_iosys_file_native_vectorized_cleanup
	(__synapse_iosys_file_native_vectorized* pVec)
{
	CloseHandle
		(pVec->hnd_file);
	free
		(pVec);
}