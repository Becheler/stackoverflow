find_package(Boost ${Boost_MINIMUM_REQUIRED} QUIET CONFIG COMPONENTS "${BOOST_COMPONENTS_REQUIRED}")

if(Boost_FOUND)
  message(STATUS "Found Boost: ${_loc} (version ${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION})")
  add_library(boost_external INTERFACE)
else()
  message(STATUS "Boost ${Boost_MINIMUM_REQUIRED} could not be located, downloading and building Boost 1.72.0 instead.")
endif()
