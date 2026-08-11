#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

#include <map>
#include <string>
#include <memory>
#include <set>
#include "resource.h"

namespace ModpackCreator
{
	struct Target
	{
		template <typename T>
		using ResourceRegistry = std::map<std::string, T>;
		std::map<std::string, ResourceRegistry<External>> external;
		std::map<std::string, ResourceRegistry<Generated>> generated;
		std::map<std::string, ResourceRegistry<File>> file;
		std::set<std::string> registered_path;
		std::shared_ptr<Target> parent;
		bool registerPath(const std::string&);
	};
} // namespace ModpackCreator

#endif // TARGET_H_INCLUDED
