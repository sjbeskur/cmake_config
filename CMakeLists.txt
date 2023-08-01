cmake_minimum_required(VERSION 3.0)
project(TemplateReplacementExample)


set(SOME_VARIABLE "10" CACHE STRING "size of the catalog")
set(CAMERA_FOV_DEGREES "1.5" CACHE STRING "field of view")

# Load the configuration from the config.txt file
file(STRINGS "config.txt" CONFIG_CONTENT)
foreach(CONFIG_LINE IN LISTS CONFIG_CONTENT)
    string(REGEX REPLACE "([^=]*)=(.*)" "\\1;\\2" CONFIG_PAIR ${CONFIG_LINE})
    list(GET CONFIG_PAIR 0 CONFIG_KEY)
    list(GET CONFIG_PAIR 1 CONFIG_VALUE)
    message("-->" ${CONFIG_KEY}  " = " ${CONFIG_VALUE})
    set(${CONFIG_KEY} ${CONFIG_VALUE})
endforeach()


# Process the template file and replace the placeholder variables
configure_file(src/template.hpp.in src/template.hpp)

# Add the executable
add_executable(my_exe src/main.cpp src/template.hpp)