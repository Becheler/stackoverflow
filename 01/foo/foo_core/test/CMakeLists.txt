cmake_minimum_required(VERSION 3.12)

### UNIT TEST

# Keep test files in a separate source directory called test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} unit_test/*.cpp)

#Run through each source
foreach(testSrc ${TEST_SRCS})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        #Add compile target
        add_executable(${testName} ${testSrc})

        #link to Boost libraries AND your targets and dependencies
        target_link_libraries(${testName}
                                Boost::unit_test_framework
                                )

        #I like to move testing binaries into a testBin directory
         set_target_properties(${testName} PROPERTIES
         RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/test/testBin)

        target_include_directories(
          ${testName} PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

        #Finally add it to test execution -
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName}
                 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/testBin
               COMMAND ${CMAKE_BINARY_DIR}/test/testBin/${testName} )
endforeach(testSrc)
