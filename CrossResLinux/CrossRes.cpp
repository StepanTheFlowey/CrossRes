#include "../include/CrossRes.hpp"

extern const ResourcePtrs resources[];

ResourceSize loadResourceSize(const uint32_t id) {
  ResourceSize resource;

  resource.data = resources[id].begin;
  resource.size = reinterpret_cast<uintptr_t>(resources[id].end) - reinterpret_cast<uintptr_t>(resources[id].begin);

  return resource;
}

ResourcePtrs loadResourcePtrs(const uint32_t id) {
  ResourcePtrs resource = resources[id];

  return resource;
}
