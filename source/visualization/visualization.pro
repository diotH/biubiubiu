
TEMPLATE = lib

QT += core widgets sql gui network xml

DEFINES +=VISUALIZATION_LIB

include(visualization.pri)
include(../publicConfig/common.pri)

TARGET = visualization

DESTDIR = $$PROJECT_ROOT_DIR

DEPENDPATH += $$PROJECT_ROOT_DIR

LIBS += -L$$PROJECT_ROOT_DIR

LIBS_LIST =

#依赖的头文件路径
INCLUDEPATH += ./include

#配置debug和release的区别
CONFIG(debug, debug|release){
    TARGET = $$join(TARGET,,,_d)
#在LIBS_LIST的每个元素前面加上-l后面加_d
    for(var, LIBS_LIST) {
    var=$$join(var,,-l)
    var=$$join(var,,,_d)
    LIBS += $$var
    }
}else{
#在LIBS_LIST的每个元素前面加上-l
    for(var, LIBS_LIST) {
    var=$$join(var,,-l)
    LIBS += $$var
    }
}

RESOURCES += \
    resource.qrc
