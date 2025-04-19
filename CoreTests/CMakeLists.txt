project(CoreTests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(CoreTests domain/shared/StringUtilsTests.cpp
        domain/model/AdvertisementAndPropertyTests.cpp
        domain/model/StoreTests.cpp
        infrastructure/memory/StoreMemoryRepositoryTests.cpp)

target_link_libraries(CoreTests Core)
target_link_libraries(CoreTests gtest gtest_main)