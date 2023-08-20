set(cmake_dir ${CMAKE_SOURCE_DIR}/cmake)
function(setup_platform_libs target_name)
    if (WIN32)
        include(${cmake_dir}/Windows.cmake)
    elseif(LINUX)
        include(${cmake_dir}/Linux.cmake)
    else()
        message(FATAL_ERROR "Your OS currently isn't supported")
    endif()
endfunction()