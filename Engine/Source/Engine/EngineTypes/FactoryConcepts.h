#pragma once

class IProduct;
class ISingletonProduct;

// regular product
template<typename T> concept TProductInterface = std::is_base_of<IProduct, T>::value;
template<typename T> concept TProductInstantible = requires { T{}; };
template<typename T> concept TProductConcept = TProductInterface<T> && TProductInstantible<T>;