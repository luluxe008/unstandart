#ifndef __USTD_MEMORY_H__
#define __USTD_MEMORY_H__

#include "exception.hpp"

// TODO create a safe way to check if 'new' work

namespace ustd {
	
	template <typename T>
	inline void check_null_pointer(T* ptr) {
		if (ptr == nullptr) {
			throw ustd::null_pointer_exception;
		}
	}

	class ReferenceCounter {
		/*
			This class help SmartPointer to know if a value can be deleted
		*/
	private:
		unsigned int count;
	public:
		void add_ref() {
			count++;
		}
		unsigned int release() {
			return --count;
		}
		ReferenceCounter() : count(0) {

		}
	};

	template<typename T>
	class SmartPointer {
			/*
				automatically delete memory after use.
				Keep track of the reference to avoid null-pointer use
			*/
			/* THIS SMART POINTER WAS MADE FOR TRAINING PURPOSE ONLY. IT MAY CONTAINS BUG AND MEMORY LEAKS. 
				DO NOT USE IN PRODUCTION UNLESS YOU KNOWN WHAT YOU ARE DOING. */
	private:


		ReferenceCounter* rc;
		T* p_data;

	public: // THIS IS A TEST I DO NOT KNOW IF LETTING RELEASE PUBLIC IS A GOOD IDEA
		void release() {

			if (is_null()) return;

			/*
			  before deleting the value we make sure that this pointer does not have other reference
			*/
			if (rc->release() == 0) {
				delete p_data;
				delete rc;

			}
			/* we forget our value*/
			p_data = nullptr;
			rc = nullptr;
		}

	public:
		SmartPointer(): p_data(nullptr), rc(nullptr) {

		}
		
		SmartPointer(T* p_ptr): p_data(nullptr), rc(nullptr) {
			check_null_pointer(p_ptr);

			rc = new ReferenceCounter();
			
			p_data = p_ptr;
			
			rc->add_ref();
		}

		~SmartPointer() {
			release();
		}

		SmartPointer(SmartPointer& sp): p_data(nullptr), rc(nullptr) {
			if (&sp == this) return; //avoid self asign
			if (sp.is_null()) return;

			p_data = sp.p_data;
			rc = sp.rc;
			rc->add_ref();
		}

		SmartPointer(const T& v) : p_data(nullptr), rc(nullptr) {			
			/*
			* allocate memory
			*/
			p_data = new T(v);

			/*
			set things up
			*/
			rc = new ReferenceCounter();
			rc->add_ref();
		}

		void operator=(SmartPointer<T>& sp) {
			release(); // forget old ptr


			p_data = sp.p_data;
			rc = sp.rc;
			rc->add_ref();

		}

		void reallocate(T* p_ptr) {
			check_null_pointer(p_ptr);
			release(); // forget old data

			p_data = p_ptr;

			rc = new ReferenceCounter();
			rc->add_ref();
		}

		void reallocate(const T& v) {
			release(); // forget old data

			/*
			* allocate memory
			*/
			p_data = new T(v);

			/*
			set things up
			*/
			rc = new ReferenceCounter();
			rc->add_ref();
		}

		T& operator*() {
			if (is_null()) {
				throw ustd::null_pointer_exception;
			}
			return *p_data;
		}

		T* operator->() {
			if (is_null()) {
				throw ustd::null_pointer_exception;
			}
			return p_data;
		}

		const T* get_ptr() const{
			return p_data; 
		}

		T* get_ptr() { // NOT SURE ABOUT THIS ##################  MAY BE UNSTABLE  ################## 
			return p_data;
		}

		bool is_null() const{
			return p_data == nullptr;
		}

		
	};
	
	template <typename T>
	using SP = SmartPointer<T>;
}

#endif // !__USTD_MEMORY_H__
