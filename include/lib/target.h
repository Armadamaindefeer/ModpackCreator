#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

#include <map>
#include <string>
#include <memory>
#include <set>
#include "resource.h"

namespace ModpackCreator
{

	template <typename T>
	using Registry = std::set<std::shared_ptr<T>>;

	template <typename T>
	using ViewRegistry = std::set<std::weak_ptr<T>,
								  std::owner_less<std::weak_ptr<T>>>;

	class Target
	{
	private:
		// ResourceManager resources;
		Registry<Resource> resources;
		ViewRegistry<Resource> deleted;

		std::map<std::string, ViewRegistry<Resource>> resources_located;
		std::set<std::string> registered_path;
		std::map<std::string, std::string> properties;

	public:
		const std::shared_ptr<Target> master;
		bool path_exist(const std::string &path);
		bool resource_exist(const std::shared_ptr<Resource> &node);

		bool path_register(const std::string &path);
		bool path_unregister(const std::string &path);
		bool resource_register(std::shared_ptr<Resource> node);

		bool bind(std::shared_ptr<Generated> sub, std::shared_ptr<Resource> master);
		bool remove(std::shared_ptr<Resource> node);
		bool destroy(std::shared_ptr<Resource> node);

		std::set<std::string> path_get(bool instanceExclusif) const;
		ViewRegistry<Resource> resource_get(bool instanceExclusif) const;
		ViewRegistry<Resource> deleted_get(bool instanceExclusif) const;
		ViewRegistry<Resource> resource_located_get(const std::string &path, bool instanceExclusif) const;
	};

	std::shared_ptr<Target> make_target();
	std::shared_ptr<Target> make_target(std::shared_ptr<Target> &base);
	// std::shared_ptr<Target> copy_target(std::shared_ptr<Target> &base);

} // namespace ModpackCreator

#endif // TARGET_H_INCLUDED
