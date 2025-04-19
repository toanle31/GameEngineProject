#pragma once

// Macro to register a class as a special singleton
// that can only be created by the provided FactoryClass
// meant to be used with SingletonContainer
#define REGISTER_SINGLETON_CLASS(ClassName, FactoryClass) \
    friend FactoryClass;\
    ClassName() = default;\
    ClassName(const ClassName& other) = delete;\
    ClassName(ClassName&& other) = delete;\
    ClassName& operator=(const ClassName& other) = delete;\
    ClassName& operator=(ClassName&& other) = delete;\
    template<typename... Ts, typename = std::enable_if_t<(sizeof...(Ts) > 0)>>\
    ClassName(Ts... args) = delete;

#define EXPORT_SMART_PTR_CLASS(Module, ClassName) \
    template class Module##_API std::shared_ptr<ClassName>;

#define NODISCARD [[nodiscard]]

#define DECLARE_SUPER(SuperClass) \
    using Super = SuperClass;