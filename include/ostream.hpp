#ifndef __USTD_OSTREAM_H__
#define __USTD_OSTREAM_H__

#include <cstdio>

namespace ustd {

	enum class OstreamIndicator{
		endl,
		newl,
		flush
	};
	using OI = OstreamIndicator;

	class Ostream {
		
	public:
		FILE* output;
		
		Ostream(FILE* file) : output(file) {

		}

		Ostream() : output(stdout) {

		}

		ustd::Ostream& operator<<(const char* s) {
			fprintf(output, "%s", s);
			return *this;
		}
		ustd::Ostream& operator<<(char c) {
			fprintf(output, "%c", c);
			return *this;
		}
		
		ustd::Ostream& operator<<(OstreamIndicator i) {
			switch (i) {
			case OstreamIndicator::endl:
				fprintf(output, "\n");
				fflush(output);
				break;

			case OstreamIndicator::flush:
				fflush(output);
				break;

			case OstreamIndicator::newl:
				fprintf(output, "\n");
				break;
			}
			return *this;
		}
		

		ustd::Ostream& operator<<(bool b) {
			if (b) fprintf(output, "true");
			else fprintf(output, "false");
			return *this;
		}
		ustd::Ostream& operator<<(int i) {
			fprintf(output, "%d", i);
			return *this;
		}
		ustd::Ostream& operator<<(long l) {
			fprintf(output, "%ld", l);
			return *this;
		}
		ustd::Ostream& operator<<(unsigned long l) {
			fprintf(output, "%lu", l);
			return *this;
		}
		ustd::Ostream& operator<<(float f) {
			fprintf(output, "%f", f);
			return *this;
		}
		ustd::Ostream& operator<<(double d) {
			fprintf(output, "%lf", d);
			return *this;
		}
		template <typename T>
		ustd::Ostream& operator<<(T* ptr) {
			fprintf(output, "%p", ptr);
			return *this;
		}
	};

}


#endif // !#define __USTD_OSTREAM_H__
