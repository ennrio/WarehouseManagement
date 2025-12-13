cmake_minimum_required(VERSION 3.16)
project(WarehouseManagement VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматическое включение MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick )

# Список исходных файлов
set(SOURCES
    main.cpp
    cpp/basicproduct.cpp
    cpp/productdecorator.cpp
    cpp/promotionalproduct.cpp
    cpp/perishableproduct.cpp
    cpp/warehouse.cpp
    cpp/supply.cpp
    cpp/employee.cpp
    cpp/supplier.cpp
    cpp/report.cpp
    cpp/stockreport.cpp
    cpp/expiredreport.cpp
    cpp/reportfactory.cpp
    cpp/stockreportfactory.cpp
    cpp/expiredreportfactory.cpp
    cpp/warehousemanager.cpp
    #cpp/product.cpp
)

# Список заголовочных файлов (опционально)
set(HEADERS
    cpp/basicproduct.h
    cpp/productdecorator.h
    cpp/promotionalproduct.h
    cpp/perishableproduct.h
    cpp/warehouse.h
    cpp/supply.h
    cpp/employee.h
    cpp/supplier.h
    cpp/report.h
    cpp/stockreport.h
    cpp/expiredreport.h
    cpp/reportfactory.h
    cpp/stockreportfactory.h
    cpp/expiredreportfactory.h
    cpp/warehousemanager.h
    cpp/product.h
    cpp/iobserver.h
)

# Создание исполняемого файла
add_executable(WarehouseManagementApp ${SOURCES} ${HEADERS} resources.qrc)

# Установка свойств для Qt
target_compile_definitions(WarehouseManagementApp PRIVATE
    QT_CORE_LIB
    QT_GUI_LIB
    QT_QML_LIB
)

target_link_libraries(WarehouseManagementApp PRIVATE
    Qt6::Core
    Qt6::Quick
)

# Включение заголовков
target_include_directories(WarehouseManagementApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp
)

# Для Qt6 можно также использовать
qt6_add_resources(WarehouseManagementApp "app_resources" resources.qrc)
