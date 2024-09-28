
#include "rogue/interfaces/api/Root.h"
#include "rogue/interfaces/api/Variable.h" 
#include <boost/python.hpp>
#include <boost/variant.hpp>

#include <iostream>

int main(int argc, char** argv) { 

  Py_Initialize();  
  boost::python::object module{boost::python::import("pyrogue.examples")};
  boost::python::object root{module.attr("ExampleRoot")()}; 

  rogue::interfaces::api::Root _root(root);
  auto nodes{_root.getNodes()};

  std::cout << "Node count: " << nodes.size() << std::endl;
  for (auto& [key, value] : nodes) { 
      std::cout << "Node name: " << key << std::endl;
      if (value.which() == 0) { 
      	std::cout << "Node value (bool): " << boost::get<rogue::interfaces::api::Variable<bool>>(value).get() << std::endl;
      } else if (value.which() == 1) { 
      	std::cout << "Node value (int): " << boost::get<rogue::interfaces::api::Variable<int>>(value).get() << std::endl;
      } else if (value.which() == 2) { 
      	std::cout << "Node value (float): " << boost::get<rogue::interfaces::api::Variable<float>>(value).get() << std::endl;
      } else if (value.which() == 3) { 
      	std::cout << "Node value (uint8_t): " << boost::get<rogue::interfaces::api::Variable<uint8_t>>(value).get() << std::endl;
      } else if (value.which() == 4) { 
      	std::cout << "Node value (uint32_t): " << boost::get<rogue::interfaces::api::Variable<uint32_t>>(value).get() << std::endl;
      } else if (value.which() == 5) { 
      	std::cout << "Node value (uint64_t): " << boost::get<rogue::interfaces::api::Variable<uint64_t>>(value).get() << std::endl;
      } else if (value.which() == 6) { 
      	std::cout << "Node value (uintmax_t): " << boost::get<rogue::interfaces::api::Variable<uintmax_t>>(value).get() << std::endl;
      } else if (value.which() == 7) { 
      	std::cout << "Node value (std::string): " << boost::get<rogue::interfaces::api::Variable<std::string>>(value).get() << std::endl;
      } 
  }

  std::cout << "Local time: " << _root.getNode<rogue::interfaces::api::Variable<std::string>>("LocalTime").get() << std::endl;
}
