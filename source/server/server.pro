
TEMPLATE = lib

QT += core widgets sql gui network

#include(visualization.pri)

TARGET = server

LIB_LIST =

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
