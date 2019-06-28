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
    DefineTemplate \
    MaxAuto \
    MaxDecltype \
    MaxDecltypeWithDecay \
    MaxCommmon \
    DefaultTemplateArguments \
    DefaultTemplateArguments2 \
    MaxOverloading \
    MaxDefault \
    MaxOverloading2 \
    Stack \
    FriendOfTemplate \
    FriendOfTemplate2 \
    Specialization \
    PartialSpecialization \
    DefaultClassTemplateArguments \
    NontypeClassTemplate \
    AddValue \
    AutoParameter \
    Message \
    VariadicTemplate \
    VariadicTemplate2 \
    FoldExpression \
    # AddSpace
    VariadicBaseClass \
    PrintColl \
    LessArray \
    Arrays \
    MemberTemplates \
    STL \
    GeneralLambda \
    VariableTemplate \
    VariableTemplate2 \
    TemplateTemplateParameters \
    Move \
    MoveForward \
    SpecialMemberFunctionTemplate \
    SpecialMemberFunctionTemplate2 \
    enable_if \
    cref \
    Foreach \
    any_of
