#pragma once
#include <Windows.h>

typedef struct __synapse_iosys_file_native_vectorized_vector
{
	size_t				  cnt_vector,
						  cnt_occupied_vector;

	FILE_SEGMENT_ELEMENT* ptr_vector;
} __synapse_iosys_file_native_vectorized_vector;

typedef struct __synapse_iosys_file_native_vectorized_request
{
	OVERLAPPED hnd_vec_aio;
	__synapse_iosys_file_native_vectorized_vector*
			   hnd_vec;
} __synapse_iosys_file_native_vectorized_request;

typedef struct __synapse_iosys_file_native_vectorized
{
	HANDLE hnd_file;
} __synapse_iosys_file_native_vectorized;