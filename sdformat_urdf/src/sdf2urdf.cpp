#include "sdformat_urdf/sdformat_urdf.hpp"
#include <cstdio>

urdf::ModelInterfaceSharedPtr parse(const std::string &){
    sdf::Errors errors;
    urdf::ModelInterfaceSharedPtr urdf_cpp = sdformat_urdf::parse(data, errors);

    if (urdf_cpp) {
      return urdf_cpp;
    }

    for (const sdf::Error & error : errors) {
      std::fprintf(stderr, "%s", error.Message().c_str());
    }
    if (errors.empty()) {
      std::fprintf(stderr, "Failed to parse but no errors reported");
    }
    return nullptr;
}

int main(int argc, char** argv){
    if(argc != 1){
        std::cerr << "usage: sdf2urdf <filename.sdf>" << std::endl;
        return 1;
    }

    auto ptr = parse(argv[0]);

    if(!ptr)
        return 1;

    std::fprintf(stdoud, "%p", ptr);
    return 0;
}