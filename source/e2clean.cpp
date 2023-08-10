
#include <boost/program_options.hpp>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

#include "ChipList.hpp"
#include "IntelHex.hpp"

namespace prog_opts = boost::program_options;

int main(int argc, char* argv[]) {
  int rc = 0;

  prog_opts::options_description desc("Usage");

  prog_opts::options_description generic("Generic options");
  desc.add_options()("help", "produce help message")("version,v",
                                                     "print version string");
  constexpr size_t listSize = sizeof(E2PROM_list) / sizeof(*E2PROM_list);
  for (size_t i = 0; i < listSize; i++)
    generic.add_options()

        (E2PROM_list[i].ShortName.c_str(), E2PROM_list[i].FullName.c_str());

  // Declare a group of options that will be
  // allowed both on command line and in
  // // config file
  // prog_opts::options_description config("Configuration");
  // config.add_options()
  //     ("optimization", prog_opts::value<int>(&opt)->default_value(10),
  //           "optimization level")
  //     // ("include-path,I",
  //     //      prog_opts::value< vector<string> >()->composing(),
  //     //      "include path")
  //     ;

  prog_opts::variables_map args;
  // std::cout << IHEX_CLEAR(0,45,10)<< desc << generic << std::endl;

  try {
    prog_opts::store(prog_opts::parse_command_line(argc, argv, generic), args);
    prog_opts::notify(args);

    //     if(args.count("algo") && args.count("exchanges") &&
    //     args.count("admin_port"))
    //     {
    //         //TODO:
    //     }
    //     else
    for (size_t i = 0; i < listSize; i++)
      if (args.count(E2PROM_list[i].ShortName.c_str())) {
        //         //TODO:
        std::ofstream ihex_file;
        ihex_file.open("./"+E2PROM_list[i].ShortName+".hex");
        ihex_file << IHEX_CLEAR(0,E2PROM_list[i].E2PROM_size,0x20);
        ihex_file.close();
      }
    //     else
    if (args.count("help")) {
      std::cout << desc << std::endl;
    }
    //     else
    //     {
    //         std::cerr << desc << std::endl;
    //         rc = 1;
    //     }
  } catch (const prog_opts::error& e) {
    //     std::cerr << "Failed start with given command line arguments: " <<
    //     e.what() << std::endl; rc = 1;
  }

  return rc;
}
