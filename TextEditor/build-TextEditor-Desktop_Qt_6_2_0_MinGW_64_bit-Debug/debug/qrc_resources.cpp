/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.2.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/C++/Qt/Geekbriains/Lesson_3/TextEditor/text.txt
  0x0,0x0,0x0,0x2b,
  0xd0,
  0x9c,0xd0,0xbd,0xd0,0xbe,0xd0,0xb3,0xd0,0xbe,0x20,0xd0,0xbf,0xd0,0xbe,0xd0,0xbb,
  0xd0,0xb5,0xd0,0xb7,0xd0,0xbd,0xd0,0xbe,0xd0,0xb3,0xd0,0xbe,0x20,0xd1,0x82,0xd0,
  0xb5,0xd0,0xba,0xd1,0x81,0xd1,0x82,0xd0,0xb0,0x2e,
  
};

static const unsigned char qt_resource_name[] = {
  // text.txt
  0x0,0x8,
  0xc,0xf7,0x54,0xb4,
  0x0,0x74,
  0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/text.txt
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x80,0x86,0x31,0xb7,0xaf,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)(); }
   } dummy;
}
