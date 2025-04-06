#pragma once

import std.compat;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using TypeIndex = std::type_index;

template <typename T> using TSharedPtr = std::shared_ptr<T>;
template <typename T> using TUniquePtr = std::unique_ptr<T>;
template <typename T> using TWeakPtr = std::weak_ptr<T>;