
#include "rogue/interfaces/api/Root.h"
#include <boost/python.hpp>

#include <iostream>

int main(int argc, char** argv) { 

  Py_Initialize();  
  boost::python::object module{boost::python::import("pyrogue.examples")};
  boost::python::object root{module.attr("ExampleRoot")()}; 

  rogue::interfaces::api::Root _root(root); 

  /*
  rogue::interfaces::api::Bsp bsp("pyrogue.examples", "ExampleRoot");

  auto nodes{bsp.nodeList()};

  for (auto i{0}; i < boost::python::len(nodes); i++) {
    std::string base_class_name{boost::python::extract<std::string>(
		    nodes[i].attr("__class__")
		            .attr("__bases__")[0].attr("__name__"))};
   
    if (base_class_name.compare("BaseCommand") == 0) {  
      std::cout << "Found command, skipping" << std::endl; 
      continue;
    } else if (base_class_name.compare("BaseVariable") == 0) {
      std::cout << "Building record." << std::endl;

      std::string record_name{boost::python::extract<std::string>(nodes[i].attr("_path"))};
      std::replace(record_name.begin(), record_name.end(), '.', ':'); 

      
      std::cout << "Record name: " << record_name << "\n";
      
      std::string type{boost::python::extract<std::string>(nodes[i].attr("typeStr"))}; 
      std::cout << "Type: " << type << "\n"; 

      if (type.compare("int") == 0) {
        std::cout << "Found int type." << std::endl;
	int value = boost::python::extract<int>(nodes[i].attr("value")); 
	std::cout << "value: " << value << std::endl;
      }

      
    }
     	

    //std::cout << base_class_name << std::endl;
  }
  */
}
