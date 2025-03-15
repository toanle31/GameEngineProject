#pragma once
namespace Bonk
{

class ENGINE_API ServiceLocator
{
public:
    template <typename T>
    static void AddService(std::shared_ptr<T> Service)
    {
        GetServicesMap()[typeid(T)] = std::static_pointer_cast<void>(Service);
    }
    
    template <typename T>
    static [[nodiscard]] std::shared_ptr<T> GetService()
    {
        auto& services = GetServicesMap();
        auto it = services.find(typeid(T));
        if (it != services.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
    
private:
    // This function is defined in the cpp file and handles the static storage
    static std::unordered_map<std::type_index, std::shared_ptr<void>>& GetServicesMap();
};

}