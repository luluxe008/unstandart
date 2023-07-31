#ifndef __USTD_EXCEPTION_H__
#define __USTD_EXCEPTION_H__


namespace ustd {
	class Exception {

	} exception;

	class AllocationFailed : public Exception {

	} allocation_failed_exception;

	class NullPointerReference : public Exception {

	} null_pointer_exception;

	class OutOfRange : public Exception {

	} out_of_range_exception;

	class BadIndex : public Exception {

	} bad_index_exception;

	class Assert : public Exception {

	} assert_exception;

	void assert(bool expr) {
		if (!expr) throw ustd::assert_exception;
	}
};

#endif // !__USTD_EXCEPTION_H__
