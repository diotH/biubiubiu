
TEMPLATE = app

QT += core widgets sql gui network

include(startProcess.pri)
include(../publicConfig/common.pri)

TARGET = starProcess

DESTDIR = $$PROJECT_ROOT_DIR

LIBS_LIST = visualization

#依赖路径
DEPENDPATH += $$PROJECT_ROOT_DIR
#静态库文件夹路径
LIBS += -L$$PROJECT_ROOT_DIR

#依赖的头文件路径
INCLUDEPATH += ./include
INCLUDEPATH += ../visualization/include

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
