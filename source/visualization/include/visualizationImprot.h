#ifndef ON_WIDGETS_H
#define ON_WIDGETS_H

#include <QtGui>
#include <QtCore>
#include <QtWidgets>

#ifdef VISUALIZATION_LIB
# define VISUALIZATION_EXPORT Q_DECL_EXPORT
#else
# define VISUALIZATION_EXPORT Q_DECL_IMPORT
#endif

#endif
