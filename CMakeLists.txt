cmake_minimum_required(VERSION 3.20)
project(LaoQGChatApp)

# 找到QT6的SDK
find_package(Qt6 COMPONENTS Quick REQUIRED)

# 设置支持构建QT信号槽和资源
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    qml.qrc
    src/Common.h src/Common.cpp
    src/Component/login.h src/Component/login.cpp
    src/Component/chat.h src/Component/chat.cpp
    src/Component/Chat/chatsession.h src/Component/Chat/chatsession.cpp
    src/Component/Chat/sessionarea.h src/Component/Chat/sessionarea.cpp
)

# 指定QT SDK导入的库
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick
)
