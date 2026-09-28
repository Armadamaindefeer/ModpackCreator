#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <string>
#include <memory>
#include <set>

namespace ModpackCreator
{
	struct Resource
	{
		// std::string id;
		std::string filename;
		std::string path;
		std::set<std::shared_ptr<Resource>> control;
		std::set<std::shared_ptr<Resource>> dependsOn;
		bool independant{true};
		virtual ~Resource() = default;
	};

	struct External : Resource
	{
		std::string supplier;
		std::string identifier;
		std::string version;
	};

	struct Generated : Resource
	{
		std::shared_ptr<Resource> master;
	};


} // namespace ModpackCreator

#endif // RESOURCE_H_INCLUDED
