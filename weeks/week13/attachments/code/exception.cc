#include <exception>
#include <stdexcept>

int main(void) {
  try {
    throw std::domain_error("Some Error Messages Here!");
  } catch (const std::exception &) {
    // handle the exception
  }

  // You can throw anything and catch anything
  try {
    // throw anything
    throw 0;
  } catch (...) { // catch anything
    // rethrow
    throw;
  }
}