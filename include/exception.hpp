#ifndef __USTD_EXCEPTION_H__
#define __USTD_EXCEPTION_H__


namespace ustd {
	class Exception {

	} ;
	extern Exception exception;

	class AllocationFailed : public Exception {

	};
	extern AllocationFailed allocation_failed_exception;

	extern AllocationFailed allocation_failed_exception;

	class NullPointerReference : public Exception {

	} ;
	extern NullPointerReference null_pointer_exception;

	class OutOfRange : public Exception {

	} ;
	extern OutOfRange out_of_range_exception;

	class BadIndex : public Exception {

	} ;
	extern BadIndex bad_index_exception;

	class Assert : public Exception {

	} ;
	extern Assert assert_exception;

};

#endif // !__USTD_EXCEPTION_H__
