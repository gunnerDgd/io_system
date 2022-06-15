#pragma once
extern "C"
{
#include <io_system/sched/file/system_sched/system_sched_type.h>
#include <io_system/sched/file/system_sched/system_sched_init.h>
}

#include <type_traits>
#include <io_system/sched/file/system_sched/cpp/system_sched_declare.hpp>

namespace io_system::schedule::system_scheduler {
	class io_session
	{
		friend class scheduler ;
		friend class io_request;

	public:
		using native_handle_type
			= synapse_iosys_sched_system_io_session;
		
	public:
		template <typename InSched, typename InFileType>
		io_session 
			(InSched&&, InFileType&&);
		~io_session();

	private:
		native_handle_type
			__M_iosys_hnd_session;
	};
}

template <typename InSched, typename InFileType>
io_system::schedule::system_scheduler::io_session::io_session
	(InSched&& pSched, InFileType&& pFile)
		: __M_iosys_hnd_session
			(synapse_iosys_sched_system_io_session_initialize(
				pSched.__M_iosys_sched_hnd, pFile.native_handle())
		) {  }