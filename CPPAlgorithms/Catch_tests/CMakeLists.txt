find_package(Catch2 3 REQUIRED)

add_executable(Catch_tests_run BubbleSortTest.cpp InsertionSortTest.cpp MergeSortTest.cpp QuickSortTest.cpp RadixSortTest.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)