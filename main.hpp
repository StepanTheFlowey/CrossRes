#pragma once

#include <stdint.h>

struct ResourceSize {
  void* data = nullptr;
  uintptr_t size = 0;
};

struct ResourcePtrs {
  void* begin = nullptr;
  void* end = nullptr;
};

ResourceSize loadResourceSize(const uint32_t id);
ResourcePtrs loadResourcePtrs(const uint32_t id);
