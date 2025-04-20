#pragma once
import std.compat;

template <
    class KeyType,
    class ValueType,
    class Hasher = std::hash<KeyType>,
    class KeyEqual = std::equal_to<KeyType>,
    class Allocator = std::allocator<std::pair<const KeyType, ValueType>>>
using TMap = std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>;

template <class ValueType, class Allocator = std::allocator<ValueType>> using TArray = std::vector<ValueType, Allocator>;
/*
{
    std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator> Data;
    
public:
    // Type definitions to match std::unordered_map
    using KVPair = std::pair<const KeyType, ValueType>;
    using SizeType = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::size_type;
    using DifferenceType = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::difference_type;
    using Reference = ValueType&;
    using ConstReference = const ValueType&;
    using Pointer = typename std::allocator_traits<Allocator>::pointer;
    using ConstPointer = typename std::allocator_traits<Allocator>::const_pointer;
    using Iterator = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::iterator;
    using ConstIterator = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::const_iterator;
    using LocalIterator = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::local_iterator;
    using ConstLocalIterator = typename std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>::const_local_iterator;

    // Constructors
    TMap() = default;
    
    explicit TMap(SizeType BucketCount,
                 const Hasher& Hash = HashFunction(),
                 const KeyEqual& Equal = KeyEqual(),
                 const Allocator& Alloc = Allocator())
        : Data(BucketCount, Hash, Equal, Alloc) {}
        
    explicit TMap(const Allocator& Alloc)
        : Data(Alloc) {}
        
    template <typename InputIt>
    TMap(InputIt First, InputIt Last,
        SizeType BucketCount = 0,
        const Hasher& Hash = HashFunction(),
        const KeyEqual& Equal = KeyEqual(),
        const Allocator& Alloc = Allocator())
        : Data(First, Last, BucketCount, Hash, Equal, Alloc) {}
        
    TMap(const TMap& Other) : Data(Other.Data) {}
    
    TMap(TMap&& Other) noexcept : Data(std::move(Other.Data)) {}
    
    TMap(std::initializer_list<ValueType> Init,
        SizeType BucketCount = 0,
        const Hasher& Hash = HashFunction(),
        const KeyEqual& Equal = KeyEqual(),
        const Allocator& Alloc = Allocator())
        : Data(Init, BucketCount, Hash, Equal, Alloc) {}

    // Assignment operators
    TMap& operator=(const TMap& Other)
    {
        Data = Other.Data;
        return *this;
    }
    
    TMap& operator=(TMap&& Other) noexcept
    {
        Data = std::move(Other.Data);
        return *this;
    }
    
    TMap& operator=(std::initializer_list<ValueType> InitList)
    {
        Data = InitList;
        return *this;
    }

    // Element access
    ValueType& At(const KeyType& Key)
    {
        return Data.at(Key);
    }
    
    const ValueType& At(const KeyType& Key) const
    {
        return Data.at(Key);
    }
    
    ValueType& operator[](const KeyType& Key)
    {
        return Data[Key];
    }
    
    ValueType& operator[](KeyType&& Key)
    {
        return Data[std::move(Key)];
    }

    // Iterators
    Iterator Begin() noexcept { return Data.begin(); }
    ConstIterator Begin() const noexcept { return Data.begin(); }
    ConstIterator CBegin() const noexcept { return Data.cbegin(); }
    
    Iterator End() noexcept { return Data.end(); }
    ConstIterator End() const noexcept { return Data.end(); }
    ConstIterator CEnd() const noexcept { return Data.cend(); }

    // Capacity
    bool Empty() const noexcept { return Data.empty(); }
    SizeType Size() const noexcept { return Data.size(); }
    SizeType MaxSize() const noexcept { return Data.max_size(); }

    // Modifiers
    void Clear() noexcept { Data.clear(); }
    
    std::pair<Iterator, bool> Insert(const ValueType& Value)
    {
        return Data.insert(Value);
    }
    
    template <typename P>
    std::pair<Iterator, bool> Insert(P&& Value)
    {
        return Data.insert(std::forward<P>(Value));
    }
    
    Iterator Insert(ConstIterator Hint, const ValueType& Value)
    {
        return Data.insert(Hint, Value);
    }
    
    template <typename P>
    Iterator Insert(ConstIterator Hint, P&& Value)
    {
        return Data.insert(Hint, std::forward<P>(Value));
    }
    
    template <typename InputIt>
    void Insert(InputIt First, InputIt Last)
    {
        Data.insert(First, Last);
    }
    
    void Insert(std::initializer_list<ValueType> InitList)
    {
        Data.insert(InitList);
    }
    
    template <typename... As>
    std::pair<Iterator, bool> Emplace(As&&... Args)
    {
        return Data.emplace(Args...);
    }

    template <typename... As>
    std::pair<Iterator, bool> Emplace(As&... Args)
    {
        return Data.emplace(std::forward<Args>(Args...));
    }
    
    Iterator Erase(ConstIterator Pos) {
        return Data.erase(Pos);
    }
    
    Iterator Erase(ConstIterator First, ConstIterator Last)
    {
        return Data.erase(First, Last);
    }
    
    SizeType Erase(const KeyType& Key)
    {
        return Data.erase(Key);
    }
    
    void Swap(TMap& Other) noexcept(noexcept(std::declval<std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>&>()
        .swap(std::declval<std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>&>())))
    {
        Data.swap(Other.Data);
    }

    // Lookup
    SizeType Count(const KeyType& Key) const 
    {
        return Data.count(Key);
    }
    
    Iterator Find(const KeyType& Key) 
    {
        return Data.find(Key);
    }
    
    ConstIterator Find(const KeyType& Key) const 
    {
        return Data.find(Key);
    }
    
    bool Contains(const KeyType& Key) const 
    {
        return Data.find(Key) != Data.end();
    }
    
    std::pair<Iterator, Iterator> EqualRange(const KeyType& Key) 
    {
        return Data.equal_range(Key);
    }
    
    std::pair<ConstIterator, ConstIterator> EqualRange(const KeyType& Key) const 
    {
        return Data.equal_range(Key);
    }

    // Bucket interface
    SizeType BucketCount() const noexcept 
    {
        return Data.bucket_count();
    }
    
    SizeType MaxBucketCount() const noexcept 
    {
        return Data.max_bucket_count();
    }
    
    SizeType BucketSize(SizeType N) const 
    {
        return Data.bucket_size(N);
    }
    
    SizeType Bucket(const KeyType& Key) const 
    {
        return Data.bucket(Key);
    }

    // Hash policy
    float LoadFactor() const noexcept 
    {
        return Data.load_factor();
    }
    
    float MaxLoadFactor() const noexcept 
    {
        return Data.max_load_factor();
    }
    
    void MaxLoadFactor(float Ml) 
    {
        Data.max_load_factor(Ml);
    }
    
    void Rehash(SizeType Count) 
    {
        Data.rehash(Count);
    }
    
    void Reserve(SizeType Count) 
    {
        Data.reserve(Count);
    }

    // Observers
    Hasher HashFunction() const
    {
        return Data.hash_function();
    }
    
    KeyEqual KeyEq() const
    {
        return Data.key_eq();
    }
    
    Allocator GetAllocator() const noexcept
    {
        return Data.get_allocator();
    }
    
    // Access to underlying map if needed
    const std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>& 
    GetRaw() const
    {
        return Data;
    }

    std::unordered_map<KeyType, ValueType, Hasher, KeyEqual, Allocator>& 
    GetRaw()
    {
        return Data;
    }
};
*/