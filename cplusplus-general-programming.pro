TEMPLATE = subdirs

# INCLUDEPATH += /opt/gcc8.2/install/include/c++/8.2.0

QMAKE_CXXFLAGS += -std=c++17

SUBDIRS += \
    traits \
    sqrtconstexpr \
    sqrt \
    RemoveAllExtents \
    HybridMetaprogramming \
    # UnitsTypesMetaprogramming
    DefineTemplate
