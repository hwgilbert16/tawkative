#pragma once

#include <string>
#include <vector>
#include <optional>

/*
Generic helper to parse command line arguments

This can be used on its own, but ideally it should be inherited so that children can implement getters
*/
class ArgumentParser {
public:
	ArgumentParser(const int* argc, const char** argv);

    template <typename T>
	std::optional<T> getArgument(const std::string& argument);

private:
	int _argc;
	std::vector<std::string> _argv{};
};
