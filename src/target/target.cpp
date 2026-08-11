#include "target.h"

bool ModpackCreator::Target::registerPath(const std::string &path)
{
	if (registered_path.find(path) != registered_path.end())
	{
		return false;
	}
	registered_path.insert(path);

	external.insert({path, {}});
	generated.insert({path, {}});
	file.insert({path, {}});

	return true;
}
