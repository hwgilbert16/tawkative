#include "utils/ArgumentParser.h"
#include <iostream>
#include <charconv>

ArgumentParser::ArgumentParser(const int* argc, const char** argv) {
	_argc = *argc;
	
	if (_argc > 1) {
		for (size_t i = 0; i < _argc; i++) {
			_argv.push_back(std::string(argv[i]));
		}
	}
}

template <typename T>
std::optional<T> ArgumentParser::getArgument(const std::string& argument) {
	for (size_t i = 1; i < _argc; i++) {
		if (
			_argv.size() >= i + 1
			&& i + 1 < _argc
			&& _argv.at(i) == "-" + argument
		) {
			std::string str = _argv.at(i + 1);

			// string args
			if constexpr (std::is_same<T, std::string>::value) {
				return str;
			}
			// int args
			else if constexpr (std::is_same<T, int>::value) {
				int intArg;

				std::from_chars_result result = std::from_chars(str.data(), str.data() + str.size(), intArg);

				if (
					result.ec == std::errc::invalid_argument
					|| result.ptr != str.data() + str.size()
				) {
					std::cerr << "\"" << str << "\" is an invalid value for argument " << argument << std::endl;
					std::exit(1);
				}

				return intArg;
			}

			break;
		}
	}

	return std::nullopt;
}
