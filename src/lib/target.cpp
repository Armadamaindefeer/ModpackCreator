#include "lib/target.h"

bool ModpackCreator::Target::path_exist(const std::string &path)
{
	if (registered_path.find(path) != registered_path.end())
	{
		return true;
	}
	return false;
}

bool ModpackCreator::Target::resource_exist(const std::shared_ptr<Resource>& node)
{
	if (not node)
	{
		return false;
	}
	ViewRegistry<Resource> all_resource = resource_get(false);

	if (resources.find(node) != resources.end())
	{
		return true;
	}
	return false;
}

bool ModpackCreator::Target::path_register(const std::string &path)
{
	if (path_exist(path))
	{
		return false;
	}
	registered_path.insert(path);
	resources_located.insert({path,{}});
	return true;
}

bool ModpackCreator::Target::path_unregister(const std::string &path)
{
	if (not path_exist(path)){
		return false;
	}
	if (not resources_located[path].empty()){
		return false;
	}
	resources_located.erase(path);
	registered_path.erase(path);
	return true;
}

bool ModpackCreator::Target::resource_register(std::shared_ptr<Resource> node)
{
	if(resource_exist(node)){
		return false;
	}
	if(not path_exist(node->path)){
		path_register(node->path);
	}
	resources.insert(node);
	//resources_located[node->path].insert(node);
	return true;
}

bool ModpackCreator::Target::bind(std::shared_ptr<Generated> sub, std::shared_ptr<Resource> master)
{
	if (not resource_exist(sub) or not resource_exist(master))
	{
		return false;
	}
	if (sub->master) // Sub node has already a master node
	{
		return false;
	}
	if(not master->independant){
		return false;
	}

	sub->master = master;
	sub->independant = false;
	master->control.insert(sub);
	
	return true;
}

bool ModpackCreator::Target::remove(std::shared_ptr<Resource> node)
{
	if (not resource_exist(node)){
		return false;
	}
	for( const auto& child : node->control){
		if( child->independant){
			continue;
		}
		remove(child);
	}
	resources.erase(node);
	resources_located.at(node->path).erase(node);
	return true;
}

bool ModpackCreator::Target::destroy(std::shared_ptr<Resource> node)
{
	return false;
}

std::set<std::string> ModpackCreator::Target::path_get(bool instanceExclusif) const
{
	std::set<std::string> out(registered_path);
	if (master and not instanceExclusif){
		out.merge(master->path_get(false));
	}
	return out;
}

ModpackCreator::ViewRegistry<ModpackCreator::Resource> ModpackCreator::Target::resource_get(bool instanceExclusif) const
{
	ViewRegistry<Resource> output;
	if(master and not instanceExclusif){
		output.merge(master->resource_get(false));
		for (const auto& del_resource : deleted){
			if(output.find(del_resource) != output.end()){
				output.extract(del_resource);
			}
		};
	}
	for (const auto& resource : resources){
		output.insert(resource);
	}
	return output;
}

ModpackCreator::ViewRegistry<ModpackCreator::Resource> ModpackCreator::Target::deleted_get(bool instanceExclusif) const
{
	ViewRegistry<Resource> output{deleted};
	if(master and not instanceExclusif){
		output.merge(master->deleted_get(false));
	}
	return output;
}

ModpackCreator::ViewRegistry<ModpackCreator::Resource> ModpackCreator::Target::resource_located_get(const std::string &path, bool instanceExclusif) const
{
	// ViewRegistry<Resource> output{resources_located[path]};
	// return output;
}

std::shared_ptr<ModpackCreator::Target> ModpackCreator::make_target()
{
	return std::make_shared<Target>();
}
