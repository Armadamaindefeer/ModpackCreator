#include <iostream>
#include <memory>
#include "lib/target.h"

template<typename T>
void printCollection(const std::string& name,const T& collection){
	std::cout <<  name <<": [ ";
	for( const auto& element: collection){
		std::cout << element << ", ";
	}
	std::cout << "]\n";
}

using namespace ModpackCreator;

int main(int, char**){
	auto dev = make_target();
	auto dev2 = make_target();

	std::shared_ptr<Resource> spt = std::make_shared<Resource>();
	spt->path = "root";
	std::weak_ptr<Resource> weak = spt;


	printCollection("path", dev->path_get(false));
	printCollection("path (ex)", dev->path_get(true));
	std::cout << dev->resource_exist(weak.lock()) << "\n";

	dev->resource_register(weak.lock());
	std::cout << dev->resource_exist(weak.lock()) << "\n";
	printCollection("path", dev->path_get(false));
	printCollection("path (ex)", dev->path_get(true));

	dev->remove(weak.lock());
	std::cout << dev->resource_exist(weak.lock()) << "\n";
	printCollection("path", dev->path_get(false));
	printCollection("path (ex)", dev->path_get(true));
}
