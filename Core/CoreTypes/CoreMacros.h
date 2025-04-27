#pragma once

#define NODISCARD [[nodiscard]]

#define UNPACK_TYPE_VAR_NAME_PATTERN(...) \


// Macro to register a class as a special singleton
// that can only be created by the provided FactoryClass
// meant to be used with SingletonContainer
#define REGISTER_SINGLETON_CLASS(ClassName, FactoryClass) \
    private: \
    friend FactoryClass; \
    ClassName() = default; \
    ClassName(const ClassName& other) = delete; \
    ClassName(ClassName&& other) = delete; \
    ClassName& operator=(const ClassName& other) = delete; \
    ClassName& operator=(ClassName&& other) = delete; \
    template<typename... Ts, typename = std::enable_if_t<(sizeof...(Ts) > 0)>> \
    ClassName(Ts... args) = delete;

// macro to help export classes for c++ smart ptrs
#define EXPORT_SMART_PTR_CLASS(Module, ClassName) \
    template class Module##_API std::shared_ptr<ClassName>; \
    template class Module##_API std::weak_ptr<ClassName>;

// declare super
#define DECLARE_SUPER(SuperClass) \
    using Super = SuperClass;

#define DEFINE_CRTP_CLASS(Base, Derived) \
    friend Derived; \
    Base() { static_assert(TCHasParametricConstructor<Derived> && TCIsDerived<Derived, Base>); }

#define TC_HAS_CONCEPT(FuncName) TCHas##FuncName
// Pattern is this_macro() { ... default implementation here ... }
// Compilation will only include one, basically a way to provide base implementation
// useful for function that doesn't really need to be overriden
#define DEFINE_CRTP_FUNCTION(RetType, FuncName, Base, Derived, ...) \
    RetType FuncName(__VA_ARGS__)\
    { \
        if constexpr (TC_HAS_CONCEPT(FuncName)<Base, Derived>)\
        {\
            return (static_cast<Derived&>(*this)).FuncName(); \
        }\
        else \
        { \
            return FuncName##_Base(__VA_ARGS__); \
        }\
    } \
    \
    RetType FuncName##_Base(__VA_ARGS__) requires (!TC_HAS_CONCEPT(FuncName)<Base, Derived>)