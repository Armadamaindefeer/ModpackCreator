#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

#include <map>
#include <string>
#include <memory>
#include "resource.h"

namespace ModpackCreator
{
	typedef int ResourceRegistry;
	struct target
	{
		std::map<std::string,ResourceRegistry> resources;
		std::shared_ptr<target> parent;
	};
} // namespace ModpackCreator

#endif //TARGET_H_INCLUDED
