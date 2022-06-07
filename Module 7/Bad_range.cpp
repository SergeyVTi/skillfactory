#include "Bad_range.h"

const char* Bad_range::what() const noexcept {
	return "ERROR: Array index is out of range!";
}
