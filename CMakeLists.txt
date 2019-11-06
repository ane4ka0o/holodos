cmake_minimum_required(VERSION 3.5)

project(holodos LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include/")


find_package(Qt5 COMPONENTS Core Quick QuickControls2 Widgets REQUIRED)

file(GLOB SOURCE_FILES
    "src/*.cpp"
)

file(GLOB HEADER_FILES "include/*.h")

#set(SOURCE_FILES "src/foodList.cpp" "include/foodList.h" "src/tablemodel.cpp" "include/tablemodel.h")

if(ANDROID)
    add_library(holodos SHARED main.cpp ${SOURCE_FILES} qml.qrc)
else()

    add_executable(holodos main.cpp ${SOURCE_FILES} ${HEADER_FILES} qml.qrc)
endif()


target_compile_definitions(holodos
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(holodos
    PRIVATE Qt5::Core Qt5::Quick Qt5::QuickControls2 Qt5::Widgets)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# These variables must use CACHE, otherwise QtCreator won't see them.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android" CACHE INTERNAL "")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so CACHE INTERNAL "")
#    endif()
#endif()
