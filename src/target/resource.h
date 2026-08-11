#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <string>
#include <memory>
#include <set>

namespace ModpackCreator
{
	struct Resource
	{
		std::string identifier;
		std::string filename;
		std::set<std::shared_ptr<Resource>> children;

		virtual ~Resource() = default;
	};

	struct External : Resource
	{
		std::string supplier;
		std::string version;
	};

	struct Generated : Resource
	{
		std::shared_ptr<Resource> master;
		std::string identifier;
	};

	struct File : Resource
	{
		int hash;
	};

} // namespace ModpackCreator

#endif // RESOURCE_H_INCLUDED
