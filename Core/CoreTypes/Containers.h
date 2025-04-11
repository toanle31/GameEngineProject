#pragma once
import std.compat;

template <typename KeyType, typename ValueType> using TMap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using TVector = std::vector<ValueType>;