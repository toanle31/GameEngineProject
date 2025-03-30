#pragma once

#define DECLARE_INSTANTIBLE_PRODUCT() \
	protected: \
		virtual void Marked_Can_Instantiate() override {};

#define DECLARE_SINGLETON_PRODUCT(ClassName) \
	private: \
		friend class SingletonObjectFactory;\
		ClassName() = default; \
		ClassName(const ClassName& Other) = delete; \
		ClassName& operator=(const ClassName& Other) = delete; \

class ENGINE_API IProduct { protected: virtual void Marked_Can_Instantiate() = 0; };
class ENGINE_API ISingletonProduct : public IProduct { DECLARE_INSTANTIBLE_PRODUCT() };